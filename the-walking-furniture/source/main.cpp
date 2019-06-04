#include <Windows.h>
#include <iostream>
#include <array>
#include <vector>
#include <vulkan/vulkan.hpp>
#include <stdexcept>
#include <string>
#include <sstream>

class Module
{
public:
	Module() = default;
	Module(const std::string& name)
	:
	Module{name.c_str()}
	{
		auto x = handle.get();
	}
	template<typename Type>
	Module(Type&& name)
	:
	handle{LoadLibrary(name)}
	{
		if(handle.get() == nullptr)
		{
			throw std::runtime_error{(std::stringstream{"Failed to initialize module "} << name << "!").str()};
		}
	}

	template<typename Function>
	auto get_function_address(const std::string& name)
	{
		return get_function_address<Function>(name.c_str());
	}
	template<typename Function, typename String>
	auto get_function_address(String&& name)
	{
		using NakedFunction = std::remove_pointer_t<Function>;
		static_assert(std::is_function_v<NakedFunction>, "That is not a function nor a function pointer!");
		return reinterpret_cast<NakedFunction*>(GetProcAddress(handle.get(), name));
	}

private:
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

int main()
{
#pragma region constants
	constexpr auto requiredInstanceExtensions = std::array
	{
		"VK_EXT_debug_report",
		"VK_EXT_debug_utils",
		"VK_KHR_surface",
		"VK_KHR_win32_surface"
	};

	constexpr auto requiredLayers = std::array
	{
		"VK_LAYER_RENDERDOC_Capture",
		"VK_LAYER_LUNARG_standard_validation"
	};
#pragma endregion

	auto vulkanLibrary = Module{"vulkan-1.dll"};

#pragma region vkGetInstanceProcAddr
	const auto vkGetInstanceProcAddr = vulkanLibrary.get_function_address<PFN_vkGetInstanceProcAddr>("vkGetInstanceProcAddr");

	if(vkGetInstanceProcAddr == nullptr)
	{
		std::cerr << "Can't load vkGetInstanceProcAddr!\n";
		return EXIT_FAILURE;
	}
#pragma endregion

#pragma region Query version
	const auto vkEnumerateInstanceVersion = reinterpret_cast<PFN_vkEnumerateInstanceVersion>(
		vkGetInstanceProcAddr(nullptr, "vkEnumerateInstanceVersion"));

	if(vkEnumerateInstanceVersion == nullptr)
	{
		std::cerr << "Can't load vkEnumerateInstanceVersion!\n";
		return EXIT_FAILURE;
	}

	auto version = std::uint32_t{};
	vkEnumerateInstanceVersion(&version);

	std::cout << "Vulkan version: " << (version >> 22 & 0x03ff) << '.' << (version >> 12 & 0x03ff) << '.' << (version & 0x0fff) << '\n';
#pragma endregion

#pragma region Dependencies
	auto unmetDependencies = requiredInstanceExtensions.size() + requiredLayers.size();

	const auto vkEnumerateInstanceExtensionProperties = reinterpret_cast<PFN_vkEnumerateInstanceExtensionProperties>(
		vkGetInstanceProcAddr(nullptr, "vkEnumerateInstanceExtensionProperties"));

	if(vkEnumerateInstanceExtensionProperties == nullptr)
	{
		std::cerr << "Can't load vkEnumerateInstanceExtensionProperties!\n";
		return EXIT_FAILURE;
	}

	{
		auto count = std::uint32_t{};
		if(vkEnumerateInstanceExtensionProperties(nullptr, &count, nullptr) != VK_SUCCESS)
		{
			std::cerr << "vkEnumerateInstanceExtensionProperties() returned an error!\n";
			return EXIT_FAILURE;
		}
		auto properties = std::vector<VkExtensionProperties>(count);
		if(vkEnumerateInstanceExtensionProperties(nullptr, &count, properties.data()) != VK_SUCCESS)
		{
			std::cerr << "vkEnumerateInstanceExtensionProperties() returned an error!\n";
			return EXIT_FAILURE;
		}

		std::cout << "Here are the list of extensions your program supports.\n";
		for(auto& property : properties)
		{
			for(auto requiredExtension : requiredInstanceExtensions)
			{
				if(std::strcmp(property.extensionName, requiredExtension) == 0)
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

	const auto vkEnumerateInstanceLayerProperties = reinterpret_cast<PFN_vkEnumerateInstanceLayerProperties>(
		vkGetInstanceProcAddr(nullptr, "vkEnumerateInstanceLayerProperties"));

	if(vkEnumerateInstanceLayerProperties == nullptr)
	{
		std::cerr << "Can't load vkEnumerateInstanceExtensionProperties!\n";
		return EXIT_FAILURE;
	}

	{
		auto count = std::uint32_t{};
		if(vkEnumerateInstanceLayerProperties(&count, nullptr) != VK_SUCCESS)
		{
			std::cerr << "vkEnumerateInstanceLayerProperties() returned an error!\n";
			return EXIT_FAILURE;
		}
		auto properties = std::vector<VkLayerProperties>(count);
		if(vkEnumerateInstanceLayerProperties(&count, properties.data()) != VK_SUCCESS)
		{
			std::cerr << "vkEnumerateInstanceLayerProperties() returned an error!\n";
			return EXIT_FAILURE;
		}

		std::cout << "Here are the list of layers your program supports.\n";
		for(auto& property : properties)
		{
			for(auto requiredExtension : requiredLayers)
			{
				if(std::strcmp(property.layerName, requiredExtension) == 0)
				{
					--unmetDependencies;
					break;
				}
			}
			std::cout << property.layerName << '\n';
			std::cout << " Vulkan version: " << (property.specVersion >> 22 & 0x03ff) << '.' << (property.specVersion >> 12 & 0x03ff) << '.' << (property.specVersion & 0x0fff) << '\n';
			std::cout << " version: " << property.implementationVersion << "\n";
			std::cout << " description: " << property.description << "\n";
			std::cout << '\n';
		}
	}
#pragma endregion

#pragma region Check requirements
	if(unmetDependencies != 0)
	{
		std::cerr << "Your program has not met the requirements of the Application.\n";
		return EXIT_FAILURE;
	}

	std::cout << "Your program has met the requirements of the Application.\n";
#pragma endregion

// #pragma region Create instance
// 	const auto vkCreateInstance = reinterpret_cast<PFN_vkCreateInstance>(
// 		vkGetInstanceProcAddr(nullptr, "vkCreateInstance"));

// 	if(vkCreateInstance == nullptr)
// 	{
// 		std::cerr << "Can't load vkCreateInstance!\n";
// 		return EXIT_FAILURE;
// 	}

// 	const auto applicationInfo = VkApplicationInfo{
// 		"The Walking Furniture",
// 		vk::MakeVersion(1,0,0),
// 		"Ikea Engine",
// 		vk::MakeVersion(1,0,0),
// 		vk::MakeVersion(1,1,0)
// 	};

// 	const auto instanceCreateInfo = VkInstanceCreateInfo{
// 		&applicationInfo,
// 		static_cast<std::uint32_t>(requiredLayers.size()),
// 		requiredLayers.data(),
// 		static_cast<std::uint32_t>(requiredInstanceExtensions.size()),
// 		requiredInstanceExtensions.data()
// 	};

// 	auto instance = VkInstance{};

// 	if(vkCreateInstance(&instanceCreateInfo, nullptr, &instance) != VK_SUCCESS)
// 	{
// 		std::cerr << "Failed to create an instance!\n";
// 		return EXIT_FAILURE;
// 	}

// 	const auto vkDestroyInstance = reinterpret_cast<PFN_vkDestroyInstance>(
// 		vkGetInstanceProcAddr(instance, "vkDestroyInstance"));

// 	if(vkDestroyInstance == nullptr)
// 	{
// 		std::cerr << "Can't load vkDestroyInstance!\n";
// 		return EXIT_FAILURE;
// 	}
	
// 	std::cout << "Vulkan instance created successfully!\n";

// 	vkDestroyInstance(instance, nullptr);
// #pragma endregion

	return EXIT_SUCCESS;
}
