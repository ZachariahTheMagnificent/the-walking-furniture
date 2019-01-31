#pragma once
#include <cstdint>
#include <vulkan/PhysicalDevice.hpp>
#include <vulkan/QueueFamilyProperties.hpp>

namespace vk
{
	typedef void (VKAPI_PTR *GetPhysicalDeviceQueueFamilyProperties)(
		PhysicalDevice physicalDevice,
		std::uint32_t* queueFamilyPropertyCount,
		QueueFamilyProperties* queueFamilyProperties
	);
}
