#pragma once
#include <vulkan/AllocationCallbacks.hpp>
#include <vulkan/API_PTR.hpp>
#include <vulkan/Device.hpp>
#include <vulkan/DeviceCreateInfo.hpp>
#include <vulkan/PhysicalDevice.hpp>
#include <vulkan/Result.hpp>

namespace vk
{
	typedef Result (VKAPI_PTR *CreateDevice)(
		PhysicalDevice physicalDevice,
		const DeviceCreateInfo* createInfo,
		const AllocationCallbacks* allocators,
		Device* device
	);
}
