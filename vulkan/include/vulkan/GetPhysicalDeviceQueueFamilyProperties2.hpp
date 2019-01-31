#pragma once
#include <cstdint>
#include <vulkan/API_PTR.hpp>
#include <vulkan/PhysicalDevice.hpp>
#include <vulkan/QueueFamilyProperties2.hpp>

namespace vk
{
	typedef void (VKAPI_PTR *GetPhysicalDeviceQueueFamilyProperties2)(
		PhysicalDevice physicalDevice,
		std::uint32_t* queueFamilyPropertyCount,
		QueueFamilyProperties2* queueFamilyProperties
	);
}
