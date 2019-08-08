#include <Windows.h>
#include <iostream>
#include <array>
#include <vector>
#if defined _WIN32
#define VK_USE_PLATFORM_WIN32_KHR
#endif
#include <vulkan/vulkan.hpp>
#include <stdexcept>
#include <string>
#include <sstream>
#include <chrono>
#include <algorithm>
#include <string_view>

class Module
{
public:
	Module() = default;
	template<typename Type>
	Module(const Type& name)
		:
		handle{ LoadLibrary(get_c_str(name)) }
	{
		if (handle.get() == nullptr)
		{
			throw std::runtime_error{ (std::stringstream{ "Failed to initialize module " } << name << "!").str() };
		}
	}

	template<typename Function, typename String>
	auto get_function_address(String&& name)
	{
		using NakedFunction = std::remove_pointer_t<Function>;
		static_assert(std::is_function_v<NakedFunction>, "That is not a function nor a function pointer!");
		return reinterpret_cast<NakedFunction*>(GetProcAddress(handle.get(), get_c_str(std::forward<String>(name))));
	}

private:
	template<typename Type>
	static const char* get_c_str(Type&& string)
	{
		if constexpr (std::is_same_v<std::decay_t<Type>, std::string>)
		{
			return string.c_str();
		}
		else
		{
			return string;
		}
	}

	class Deleter
	{
	public:
		using pointer = HMODULE;

		void operator()(HMODULE module) const noexcept
		{
			FreeLibrary(module);
		}
	};

	std::unique_ptr<HMODULE, Deleter> handle{};
};

struct VulkanVersion
{
	VulkanVersion() = default;
	constexpr VulkanVersion(const std::uint32_t value) noexcept
		:
		VulkanVersion{ value >> 22, value >> 12, value }
	{
	}
	constexpr VulkanVersion(const std::uint32_t major, const std::uint32_t minor, const std::uint32_t patch) noexcept
		:
		patch{ patch },
		minor{ minor },
		major{ major }
	{
	}

	constexpr operator std::uint32_t() const noexcept
	{
		return patch | minor << 12 | major << 22;
	}

	std::uint32_t patch : 12;
	std::uint32_t minor : 10;
	std::uint32_t major : 10;
};

class VulkanModule : public Module
{
public:
	VulkanModule()
		:
		Module{ "vulkan-1.dll" }
	{

	}

	PFN_vkGetInstanceProcAddr vkGetInstanceProcAddr = get_function_address<PFN_vkGetInstanceProcAddr>("vkGetInstanceProcAddr");

	PFN_vkEnumerateInstanceVersion vkEnumerateInstanceVersion = reinterpret_cast<PFN_vkEnumerateInstanceVersion>(vkGetInstanceProcAddr(nullptr, "vkEnumerateInstanceVersion"));

	PFN_vkEnumerateInstanceExtensionProperties vkEnumerateInstanceExtensionProperties = reinterpret_cast<PFN_vkEnumerateInstanceExtensionProperties>(vkGetInstanceProcAddr(nullptr, "vkEnumerateInstanceExtensionProperties"));

	PFN_vkEnumerateInstanceLayerProperties vkEnumerateInstanceLayerProperties = reinterpret_cast<PFN_vkEnumerateInstanceLayerProperties>(vkGetInstanceProcAddr(nullptr, "vkEnumerateInstanceLayerProperties"));

	PFN_vkCreateInstance vkCreateInstance = reinterpret_cast<PFN_vkCreateInstance>(vkGetInstanceProcAddr(nullptr, "vkCreateInstance"));

private:
};

VkBool32 VKAPI_PTR vkDebugUtilsMessengerCallbackEXT
(
	VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
	VkDebugUtilsMessageTypeFlagsEXT messageTypes,
	const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
	void* pUserData
)
{
	std::clog << pCallbackData->pMessage << '\n';
	return VK_FALSE;
}

void run(const HMODULE applicationInstance)
{
	constexpr auto requiredInstanceExtensions = std::array
	{
		VK_EXT_DEBUG_UTILS_EXTENSION_NAME,
		VK_KHR_SURFACE_EXTENSION_NAME,
		VK_KHR_WIN32_SURFACE_EXTENSION_NAME,
		VK_KHR_GET_PHYSICAL_DEVICE_PROPERTIES_2_EXTENSION_NAME,
		VK_KHR_GET_SURFACE_CAPABILITIES_2_EXTENSION_NAME
	};

	constexpr auto requiredDeviceExtensions = std::array
	{
		VK_KHR_SWAPCHAIN_EXTENSION_NAME
	};

	constexpr auto requiredLayers = std::array
	{
		"VK_LAYER_KHRONOS_validation"
	};

	auto windowClass = WNDCLASSEX{};
	windowClass.cbSize = sizeof(windowClass);
	windowClass.lpfnWndProc = DefWindowProc;
	windowClass.hInstance = applicationInstance;
	windowClass.lpszClassName = "Window";
	const auto atom = RegisterClassEx(&windowClass);

	if (atom == 0)
	{
		throw std::runtime_error{ "Failed to register window class!" };
	}

	auto window = CreateWindowEx
	(
		0,
		reinterpret_cast<LPCSTR>(atom),
		"The Walking Furniture",
		WS_POPUP,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		800,
		600,
		nullptr,
		nullptr,
		applicationInstance,
		nullptr
	);

	if (window == nullptr)
	{
		throw std::runtime_error{ "Failed to create window!" };
	}

	auto vulkanModule = VulkanModule{};

	auto version = VulkanVersion{ vk::enumerateInstanceVersion(vulkanModule) };

	std::cout << "Vulkan version: " << version.major << '.' << version.minor << '.' << version.patch << '\n';
	std::cout << '\n';

	auto unmetDependencies = requiredInstanceExtensions.size() + requiredLayers.size();

	{
		const auto properties = vk::enumerateInstanceExtensionProperties(nullptr, vulkanModule);

		std::cout << "Here are the list of extensions your program supports.\n";
		for (auto& property : properties)
		{
			for (auto requiredExtension : requiredInstanceExtensions)
			{
				if (std::strcmp(property.extensionName, requiredExtension) == 0)
				{
					--unmetDependencies;
					break;
				}
			}

			std::cout << property.extensionName << '\n';
			std::cout << " version: " << property.specVersion << "\n";
			std::cout << '\n';
		}
	}

	std::cout << '\n';

	{
		const auto properties = vk::enumerateInstanceLayerProperties(std::allocator<vk::LayerProperties>{}, vulkanModule);

		std::cout << "Here are the list of layers your program supports.\n";
		for (auto& property : properties)
		{
			for (auto requiredExtension : requiredLayers)
			{
				if (std::strcmp(property.layerName, requiredExtension) == 0)
				{
					--unmetDependencies;
					break;
				}
			}
			const auto unpackedSpecVersion = VulkanVersion{ property.specVersion };
			std::cout << property.layerName << '\n';
			std::cout << " Vulkan version: " << unpackedSpecVersion.major << '.' << unpackedSpecVersion.minor << '.' << unpackedSpecVersion.patch << '\n';
			std::cout << " version: " << property.implementationVersion << "\n";
			std::cout << " description: " << property.description << "\n";
			std::cout << '\n';
		}
	}

	std::cout << '\n';

	std::find_if
	(
		requiredLayers.begin(),
		requiredLayers.end(),
		[](auto a)
		{
			return true;
		}
	);

	if (unmetDependencies != 0)
	{
		throw std::runtime_error{ "Your program has not met the requirements of the Application.\n" };
	}

	std::cout << "Your program has met the requirements of the Application.\n";
	std::cout << '\n';

	const auto applicationInfo = vk::ApplicationInfo
	{
		"The Walking Furniture",
		VulkanVersion{ 1, 0, 0 },
		"Ikea Engine",
		VulkanVersion{ 1, 0, 0 },
		VulkanVersion{ 1, 1, 0 }
	};

	const auto instanceCreateInfo = vk::InstanceCreateInfo
	{
		vk::InstanceCreateFlags{},
		&applicationInfo,
		static_cast<std::uint32_t>(requiredLayers.size()),
		requiredLayers.data(),
		static_cast<std::uint32_t>(requiredInstanceExtensions.size()),
		requiredInstanceExtensions.data()
	};

	auto instance = vk::createInstance<VulkanModule>(instanceCreateInfo, nullptr, vulkanModule);

	if (!instance)
	{
		throw std::runtime_error{ "Failed to create an instance!\n" };
	}

	auto dispatchTable = vk::DispatchLoaderDynamic{ instance, vulkanModule.vkGetInstanceProcAddr };

	std::cout << "Vulkan instance created successfully!\n";
	std::cout << '\n';

	auto debugMessengerCreateInfo = vk::DebugUtilsMessengerCreateInfoEXT
	{
		vk::DebugUtilsMessengerCreateFlagsEXT{},
		vk::DebugUtilsMessageSeverityFlagBitsEXT::eWarning | vk::DebugUtilsMessageSeverityFlagBitsEXT::eError | vk::DebugUtilsMessageSeverityFlagBitsEXT::eWarning | vk::DebugUtilsMessageSeverityFlagBitsEXT::eVerbose,
		vk::DebugUtilsMessageTypeFlagBitsEXT::eGeneral | vk::DebugUtilsMessageTypeFlagBitsEXT::eValidation | vk::DebugUtilsMessageTypeFlagBitsEXT::ePerformance,
		vkDebugUtilsMessengerCallbackEXT,
		nullptr,
	};
	auto debugMessenger = instance.createDebugUtilsMessengerEXT(debugMessengerCreateInfo, nullptr, dispatchTable);
	if (!debugMessenger)
	{
		instance.destroy(nullptr, dispatchTable);
		throw std::runtime_error{ "Can't create DebugUtilsMessenger!\n" };
	}

	std::cout << "Successfully created DebugUtilsMessenger!\n";
	std::cout << '\n';

	auto win32SurfaceCreateInfo = vk::Win32SurfaceCreateInfoKHR
	{
		vk::Win32SurfaceCreateFlagsKHR{},
		applicationInstance,
		window
	};

	auto surface = instance.createWin32SurfaceKHR(win32SurfaceCreateInfo, nullptr, dispatchTable);

	if (!surface)
	{
		instance.destroy(debugMessenger, nullptr, dispatchTable);
		instance.destroy(nullptr, dispatchTable);
		throw std::runtime_error{ "Can't create Win32 Surface!\n" };
	}

	std::cout << "Successfully created a Win32 Surface!\n";
	std::cout << '\n';

	const auto devices = instance.enumeratePhysicalDevices(dispatchTable);
	auto chosenDevice = devices.end();
	auto chosenDeviceProperties = vk::PhysicalDeviceProperties2{};
	{
		std::cout << "Here are the devices you have that support Vulkan:\n";

		for (auto it = devices.begin(), end = devices.end(); it != end; ++it)
		{
			const auto& device = *it;

			auto unmetDependencies = requiredDeviceExtensions.size() + requiredLayers.size();
			auto hasRequiredQueue = false;

			const auto properties = device.getProperties2(dispatchTable);
			std::cout << "Name: " << properties.properties.deviceName << '\n';
			std::cout << "Type: ";
			switch (properties.properties.deviceType)
			{
				case vk::PhysicalDeviceType::eDiscreteGpu:
					std::cout << "GPU\n";
					break;

				case vk::PhysicalDeviceType::eIntegratedGpu:
					std::cout << "Integrated GPU\n";
					break;

				case vk::PhysicalDeviceType::eVirtualGpu:
					std::cout << "Virtual GPU\n";
					break;

				case vk::PhysicalDeviceType::eCpu:
					std::cout << "CPU\n";
					break;

				case vk::PhysicalDeviceType::eOther:
					std::cout << "Unknown\n";
					break;
			}

			auto version = VulkanVersion{ properties.properties.apiVersion };
			std::cout << "Version: " << version.major << '.' << version.minor << '.' << version.patch << '\n';

			std::cout << '\n';

			{
				const auto properties = device.enumerateDeviceExtensionProperties(nullptr, dispatchTable);

				std::cout << "Here are the list of extensions the device supports.\n";
				for (auto& property : properties)
				{
					if (std::find_if(requiredDeviceExtensions.begin(), requiredDeviceExtensions.end(), [property](const auto& extension)
					{
						return std::strcmp(property.extensionName, extension) == 0;
					}) != requiredDeviceExtensions.end())
					{
						--unmetDependencies;
					}

					std::cout << property.extensionName << '\n';
					std::cout << " version: " << property.specVersion << "\n";
					std::cout << '\n';
				}
			}

			std::cout << '\n';

			{
				const auto properties = device.enumerateDeviceLayerProperties(dispatchTable);

				std::cout << "Here are the list of layers the device supports.\n";
				for (auto& property : properties)
				{
					if (std::find_if(requiredLayers.begin(), requiredLayers.end(), [property](const auto& layer)
					{
						return std::strcmp(property.layerName, layer) == 0;
					}) != requiredLayers.end())
					{
						--unmetDependencies;
					}
					const auto unpackedSpecVersion = VulkanVersion{ property.specVersion };
					std::cout << property.layerName << '\n';
					std::cout << " Vulkan version: " << unpackedSpecVersion.major << '.' << unpackedSpecVersion.minor << '.' << unpackedSpecVersion.patch << '\n';
					std::cout << " version: " << property.implementationVersion << "\n";
					std::cout << " description: " << property.description << "\n";
					std::cout << '\n';
				}
			}

			std::cout << '\n';

			const auto features = device.getFeatures2(dispatchTable);

			const auto queueFamiliesProperties = device.getQueueFamilyProperties2(dispatchTable);

			std::cout << "Here are a list of queue families your device has.\n";
			auto id = std::size_t{};
			for (const auto& queueFamilyProperties : queueFamiliesProperties)
			{
				std::cout << '#' << id << ":\n";
				std::cout << " Queue count: " << queueFamilyProperties.queueFamilyProperties.queueCount << '\n';
				std::cout << "Supports Graphics: " << std::boolalpha << bool{ queueFamilyProperties.queueFamilyProperties.queueFlags & vk::QueueFlagBits::eGraphics } << '\n';
				std::cout << "Supports Compute: " << std::boolalpha << bool{ queueFamilyProperties.queueFamilyProperties.queueFlags & vk::QueueFlagBits::eCompute } << '\n';
				std::cout << "Supports Data Transfer: " << std::boolalpha << bool{ queueFamilyProperties.queueFamilyProperties.queueFlags & vk::QueueFlagBits::eTransfer } << '\n';
				std::cout << "Supports Sparce Memory: " << std::boolalpha << bool{ queueFamilyProperties.queueFamilyProperties.queueFlags & vk::QueueFlagBits::eSparseBinding } << '\n';
				std::cout << "Supports Protected Memory: " << std::boolalpha << bool{ queueFamilyProperties.queueFamilyProperties.queueFlags & vk::QueueFlagBits::eProtected } << '\n';
				++id;

				if (queueFamilyProperties.queueFamilyProperties.queueFlags & vk::QueueFlagBits::eGraphics && queueFamilyProperties.queueFamilyProperties.queueFlags & vk::QueueFlagBits::eCompute)
				{
					hasRequiredQueue = true;
				}
			}

			if (unmetDependencies == 0 && hasRequiredQueue)
			{
				chosenDevice = it;
				chosenDeviceProperties = properties;
			}

			std::cout << '\n';
		}
	}

	if (chosenDevice == devices.end())
	{
		throw std::runtime_error{ "You do not have a device capable of running this program." };
	}

	std::cout << "We have chosen The " << chosenDeviceProperties.properties.deviceName << " to run the program.\n";
	std::cout << '\n';

	auto queueCreateInfos = std::array
	{
		vk::DeviceQueueCreateInfo
	{
		vk::DeviceQueueCreateFlags{},
		0,
		1
	}
	};

	auto deviceCreateInfo = vk::DeviceCreateInfo
	{
		vk::DeviceCreateFlags{},
		1,

	};
	//auto device = chosenDevice->createDevice(deviceCreateInfo, nullptr, dispatchTable);

	MSG message;
	ShowWindow(window, SW_SHOW);

	const auto start_time = std::chrono::steady_clock::now();
	for (auto duration = 0.0; duration < 5; duration = std::chrono::duration<double>{ std::chrono::steady_clock::now() - start_time }.count())
	{
		if (PeekMessage(&message, window, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&message);
			DispatchMessage(&message);
		}
	}

	instance.destroy(debugMessenger, nullptr, dispatchTable);
	instance.destroy(surface, nullptr, dispatchTable);
	instance.destroy(nullptr, dispatchTable);

	DestroyWindow(window);
	UnregisterClass(reinterpret_cast<LPCSTR>(atom), applicationInstance);
}

int main()
{
	try
	{
		run(GetModuleHandle(nullptr));
	}
	catch (std::exception& exception)
	{
		std::cerr << exception.what() << '\n';
	}
	return EXIT_SUCCESS;
}
