#pragma once
#include <vulkan/khr/PhysicalDeviceProperties2.hpp>
#include <vulkan/API_PTR.hpp>
#include <vulkan/PhysicalDevice.hpp>

namespace vk::khr
{
	typedef void (VKAPI_PTR *GetPhysicalDeviceProperties2)(
		PhysicalDevice device,
		PhysicalDeviceProperties2* properties
	);
}
