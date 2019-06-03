#pragma once
#include <cstdint>
#include <vulkan/DeviceCreateFlags.hpp>
#include <vulkan/DeviceQueueCreateInfo.hpp>
#include <vulkan/OutputStructure.hpp>
#include <vulkan/PhysicalDeviceFeatures.hpp>

namespace vk
{
	struct DeviceCreateInfo : InputStructure
	{
		DeviceCreateFlags flags;
		std::uint32_t queueCreateInfoCount;
		const DeviceQueueCreateInfo* queueCreateInfos;
		std::uint32_t enabledLayerCount;
		const char* const* enabledLayerNames;
		std::uint32_t enabledExtensionCount;
		const char* const* enabledExtensionNames;
		const PhysicalDeviceFeatures* enabledFeatures;
	};
}
