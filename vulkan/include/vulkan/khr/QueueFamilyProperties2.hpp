#pragma once
#include <cstdint>
#include <vulkan/PhysicalDevice.hpp>
#include <vulkan/khr/QueueFamilyProperties2.hpp>

namespace vk::khr
{
	void GetPhysicalDeviceQueueFamilyProperties2(
		PhysicalDevice physicalDevice,
		std::uint32_t* queueFamilyPropertyCount,
		QueueFamilyProperties2* queueFamilyProperties
	);
}
