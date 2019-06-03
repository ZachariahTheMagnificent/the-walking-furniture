#pragma once
#include <vulkan/AllocationCallbacks.hpp>
#include <vulkan/API_PTR.hpp>
#include <vulkan/Device.hpp>

namespace vk
{
	typedef void (VKAPI_PTR *DestroyDevice)(
		Device device,
		const AllocationCallbacks* allocators
	);
}
