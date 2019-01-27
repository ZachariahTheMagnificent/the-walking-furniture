#include <Windows.h>
#include <vulkan/vulkan.hpp>
#include <iostream>

int main()
{
	const auto vulkanLibrary = LoadLibrary("vulkan-1.dll");
	if(vulkanLibrary == nullptr)
	{
		std::cerr << "Can't open library!\n";
		return EXIT_FAILURE;
	}

	const auto vkGetInstanceProcAddr = reinterpret_cast<vk::GetInstanceProcAddr>(GetProcAddress(vulkanLibrary, "vkGetInstanceProcAddr"));

	if(vkGetInstanceProcAddr == nullptr)
	{
		std::cerr << "Can't load vkGetInstanceProcAddr!\n";
		FreeLibrary(vulkanLibrary);
		return EXIT_FAILURE;
	}

	const auto vkEnumerateInstanceVersion = reinterpret_cast<vk::EnumerateInstanceVersion>(vkGetInstanceProcAddr(nullptr, "vkEnumerateInstanceVersion"));

	if(vkEnumerateInstanceVersion == nullptr)
	{
		std::cerr << "Can't load vkEnumerateInstanceVersion!\n";
		FreeLibrary(vulkanLibrary);
		return EXIT_FAILURE;
	}

	auto version = std::uint32_t{};
	vkEnumerateInstanceVersion(&version);

	std::cout << "Vulkan version: " << (version >> 22 & 0x03ff) << '.' << (version >> 12 & 0x03ff) << '.' << (version & 0x0fff) << '\n';

	const auto vkEnumerateInstanceExtensionProperties = reinterpret_cast<vk::EnumerateInstanceExtensionProperties>(vkGetInstanceProcAddr(nullptr, "vkEnumerateInstanceExtensionProperties"));

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
		auto properties = new vk::ExtensionProperties[count];
		if(vkEnumerateInstanceExtensionProperties(nullptr, &count, properties) != vk::Result::success)
		{
			std::cerr << "vkEnumerateInstanceExtensionProperties() returned an error!\n";
			delete [] properties;
			FreeLibrary(vulkanLibrary);
			return EXIT_FAILURE;
		}

		std::cout << "Here are the list of extensions your program supports.\n";
		for(auto i = std::size_t{}; i < count; ++i)
		{
			std::cout << properties[i].extensionName << ": version " << properties[i].specVersion << "\n";
		}

		delete [] properties;
	}

	FreeLibrary(vulkanLibrary);
	return EXIT_SUCCESS;
}
