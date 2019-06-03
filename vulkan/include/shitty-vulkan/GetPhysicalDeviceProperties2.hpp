#pragma once
#include <vulkan/API_PTR.hpp>
#include <vulkan/PhysicalDevice.hpp>
#include <vulkan/PhysicalDeviceProperties2.hpp>

namespace vk
{
	typedef void (VKAPI_PTR *GetPhysicalDeviceProperties2)(
		PhysicalDevice physicalDevice,
		PhysicalDeviceProperties2* properties);
}