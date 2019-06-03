#pragma once
#include <cstdint>
#include <vulkan/khr/PhysicalDeviceGroupProperties.hpp>
#include <vulkan/API_PTR.hpp>
#include <vulkan/Instance.hpp>
#include <vulkan/Result.hpp>

namespace vk::khr
{
	typedef Result (VKAPI_PTR *EnumeratePhysicalDeviceGroups)(
		Instance instance,
		std::uint32_t* physicalDeviceGroupCount,
		PhysicalDeviceGroupProperties* physicalDeviceGroupProperties
	);
}
