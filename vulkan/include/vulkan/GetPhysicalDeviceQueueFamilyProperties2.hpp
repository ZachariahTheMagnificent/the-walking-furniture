#pragma once
#include <cstdint>
#include <vulkan/PhysicalDevice.hpp>
#include <vulkan/QueueFamilyProperties2.hpp>

namespace vk
{
	void GetPhysicalDeviceQueueFamilyProperties2(
		PhysicalDevice physicalDevice,
		std::uint32_t* pQueueFamilyPropertyCount,
		QueueFamilyProperties2* pQueueFamilyProperties
	);
}
