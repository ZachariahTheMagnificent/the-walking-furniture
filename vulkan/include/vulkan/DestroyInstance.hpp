#pragma once
#include <vulkan/AllocationCallbacks.hpp>
#include <vulkan/API_PTR.hpp>
#include <vulkan/Instance.hpp>

namespace vk
{
	typedef void (VKAPI_PTR *DestroyInstance)(
		Instance instance,
		const AllocationCallbacks* pAllocator);
}
