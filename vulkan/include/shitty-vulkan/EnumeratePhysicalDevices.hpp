#pragma once
#include <cstdint>
#include <vulkan/API_PTR.hpp>
#include <vulkan/Instance.hpp>
#include <vulkan/PhysicalDevice.hpp>
#include <vulkan/Result.hpp>

namespace vk
{
	typedef Result (VKAPI_PTR *EnumeratePhysicalDevices)(
		Instance instance,
		std::uint32_t* physicalDeviceCount,
		PhysicalDevice* physicalDevices
	);
}
