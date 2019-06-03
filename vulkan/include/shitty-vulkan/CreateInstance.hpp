#pragma once
#include <vulkan/AllocationCallbacks.hpp>
#include <vulkan/API_PTR.hpp>
#include <vulkan/Instance.hpp>
#include <vulkan/InstanceCreateInfo.hpp>
#include <vulkan/Result.hpp>

namespace vk
{
	typedef Result (VKAPI_PTR *CreateInstance)(
		const InstanceCreateInfo* info,
		const AllocationCallbacks* allocators,
		Instance* output
	);
}
