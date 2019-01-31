#pragma once
#include <cstdint>
#include <vulkan/Bool.hpp>
#include <vulkan/OutputStructure.hpp>
#include <vulkan/PhysicalDevice.hpp>
#include <vulkan/maxDeviceGroupSize.hpp>

namespace vk
{
	struct PhysicalDeviceGroupProperties : OutputStructure
	{
		std::uint32_t physicalDeviceCount;
		PhysicalDevice physicalDevices[maxDeviceGroupSize];
		Bool subsetAllocation;
	};
}
