#include <Windows.h>
#include <vulkan/vulkan.hpp>
#include <iostream>
#include <array>
#include <vector>

int main()
{
#pragma region constants
	constexpr auto requiredInstanceExtensions = std::array{
		"VK_EXT_debug_report",
		"VK_EXT_debug_utils",
		"VK_KHR_surface",
		"VK_KHR_win32_surface"
	};

	constexpr auto requiredLayers = std::array{
		"VK_LAYER_RENDERDOC_Capture",
		"VK_LAYER_LUNARG_standard_validation"
	};
#pragma endregion

#pragma region load library
	const auto vulkanLibrary = LoadLibrary("vulkan-1.dll");
	if(vulkanLibrary == nullptr)
	{
		std::cerr << "Can't open library!\n";
		return EXIT_FAILURE;
	}
#pragma endregion

#pragma region vkGetInstanceProcAddr
	const auto vkGetInstanceProcAddr = reinterpret_cast<vk::GetInstanceProcAddr>(
		GetProcAddress(vulkanLibrary, "vkGetInstanceProcAddr"));

	if(vkGetInstanceProcAddr == nullptr)
	{
		std::cerr << "Can't load vkGetInstanceProcAddr!\n";
		FreeLibrary(vulkanLibrary);
		return EXIT_FAILURE;
	}
#pragma endregion

#pragma region Query version
	const auto vkEnumerateInstanceVersion = reinterpret_cast<vk::EnumerateInstanceVersion>(
		vkGetInstanceProcAddr(nullptr, "vkEnumerateInstanceVersion"));

	if(vkEnumerateInstanceVersion == nullptr)
	{
		std::cerr << "Can't load vkEnumerateInstanceVersion!\n";
		FreeLibrary(vulkanLibrary);
		return EXIT_FAILURE;
	}

	auto version = std::uint32_t{};
	vkEnumerateInstanceVersion(&version);

	std::cout << "Vulkan version: " << vk::PrintableVersion(version) << '\n';
#pragma endregion

#pragma region Dependencies
	auto unmetDependencies = requiredInstanceExtensions.size() + requiredLayers.size();

	const auto vkEnumerateInstanceExtensionProperties = reinterpret_cast<vk::EnumerateInstanceExtensionProperties>(
		vkGetInstanceProcAddr(nullptr, "vkEnumerateInstanceExtensionProperties"));

	if(vkEnumerateInstanceExtensionProperties == nullptr)
	{
		std::cerr << "Can't load vkEnumerateInstanceExtensionProperties!\n";
		FreeLibrary(vulkanLibrary);
		return EXIT_FAILURE;
	}

	{
		auto count = std::uint32_t{};
		if(vkEnumerateInstanceExtensionProperties(nullptr, &count, nullptr) != vk::Result::success)
		{
			std::cerr << "vkEnumerateInstanceExtensionProperties() returned an error!\n";
			FreeLibrary(vulkanLibrary);
			return EXIT_FAILURE;
		}
		auto properties = std::vector<vk::ExtensionProperties>(count);
		if(vkEnumerateInstanceExtensionProperties(nullptr, &count, properties.data()) != vk::Result::success)
		{
			std::cerr << "vkEnumerateInstanceExtensionProperties() returned an error!\n";
			FreeLibrary(vulkanLibrary);
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

	const auto vkEnumerateInstanceLayerProperties = reinterpret_cast<vk::EnumerateInstanceLayerProperties>(
		vkGetInstanceProcAddr(nullptr, "vkEnumerateInstanceLayerProperties"));

	if(vkEnumerateInstanceLayerProperties == nullptr)
	{
		std::cerr << "Can't load vkEnumerateInstanceExtensionProperties!\n";
		FreeLibrary(vulkanLibrary);
		return EXIT_FAILURE;
	}

	{
		auto count = std::uint32_t{};
		if(vkEnumerateInstanceLayerProperties(&count, nullptr) != vk::Result::success)
		{
			std::cerr << "vkEnumerateInstanceLayerProperties() returned an error!\n";
			FreeLibrary(vulkanLibrary);
			return EXIT_FAILURE;
		}
		auto properties = std::vector<vk::LayerProperties>(count);
		if(vkEnumerateInstanceLayerProperties(&count, properties.data()) != vk::Result::success)
		{
			std::cerr << "vkEnumerateInstanceLayerProperties() returned an error!\n";
			FreeLibrary(vulkanLibrary);
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
			std::cout << " Vulkan version: " << vk::PrintableVersion(property.specVersion) << '\n';
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
		FreeLibrary(vulkanLibrary);
		return EXIT_FAILURE;
	}

	std::cout << "Your program has met the requirements of the Application.\n";
#pragma endregion

	const auto vkCreateInstance = reinterpret_cast<vk::CreateInstance>(
		vkGetInstanceProcAddr(nullptr, "vkCreateInstance"));

	if(vkCreateInstance == nullptr)
	{
		std::cerr << "Can't load vkCreateInstance!\n";
		FreeLibrary(vulkanLibrary);
		return EXIT_FAILURE;
	}

	const auto applicationInfo = vk::ApplicationInfo{
		"The Walking Furniture",
		vk::MakeVersion(1,0,0),
		"Ikea Engine",
		vk::MakeVersion(1,0,0),
		vk::MakeVersion(1,1,0)
	};

	const auto instanceCreateInfo = vk::InstanceCreateInfo{
		&applicationInfo,
		static_cast<std::uint32_t>(requiredLayers.size()),
		requiredLayers.data(),
		static_cast<std::uint32_t>(requiredInstanceExtensions.size()),
		requiredInstanceExtensions.data()
	};

	auto instance = vk::Instance{};

	if(vkCreateInstance(&instanceCreateInfo, nullptr, &instance) != vk::Result::success)
	{
		std::cerr << "Failed to create an instance!\n";
		FreeLibrary(vulkanLibrary);
		return EXIT_FAILURE;
	}

	const auto vkDestroyInstance = reinterpret_cast<vk::DestroyInstance>(
		vkGetInstanceProcAddr(instance, "vkDestroyInstance"));

	if(vkDestroyInstance == nullptr)
	{
		std::cerr << "Can't load vkDestroyInstance!\n";
		FreeLibrary(vulkanLibrary);
		return EXIT_FAILURE;
	}
	
	std::cout << "Vulkan instance created successfully!\n";

	vkDestroyInstance(instance, nullptr);
	FreeLibrary(vulkanLibrary);
	return EXIT_SUCCESS;
}
