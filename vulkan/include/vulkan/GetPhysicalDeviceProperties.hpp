#pragma once
#include <vulkan/API_PTR.hpp>
#include <vulkan/PhysicalDevice.hpp>
#include <vulkan/PhysicalDeviceProperties.hpp>

namespace vk
{
	typedef void (VKAPI_PTR *GetPhysicalDeviceProperties)(
		PhysicalDevice physicalDevice,
		PhysicalDeviceProperties* pProperties);
}
