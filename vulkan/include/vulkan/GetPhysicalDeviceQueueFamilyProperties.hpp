#pragma once
#include <cstdint>
#include <vulkan/PhysicalDevice.hpp>
#include <vulkan/QueueFamilyProperties.hpp>

namespace vk
{
	void GetPhysicalDeviceQueueFamilyProperties(
		PhysicalDevice physicalDevice,
		std::uint32_t* queueFamilyPropertyCount,
		QueueFamilyProperties* queueFamilyProperties
	);
}
