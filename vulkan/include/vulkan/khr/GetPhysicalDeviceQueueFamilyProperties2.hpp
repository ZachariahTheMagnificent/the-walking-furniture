#pragma once
#include <cstdint>
#include <vulkan/khr/QueueFamilyProperties2.hpp>
#include <vulkan/API_PTR.hpp>
#include <vulkan/PhysicalDevice.hpp>

namespace vk::khr
{
	typedef void (VKAPI_PTR *GetPhysicalDeviceQueueFamilyProperties2)(
		PhysicalDevice device,
		std::uint32_t* queueFamilyPropertyCount,
		QueueFamilyProperties2* queueFamilyProperties
	);
}
