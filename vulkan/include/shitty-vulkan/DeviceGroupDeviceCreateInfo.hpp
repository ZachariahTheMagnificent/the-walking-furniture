#pragma once
#include <cstdint>
#include <vulkan/InputStructure.hpp>
#include <vulkan/PhysicalDevice.hpp>

namespace vk
{
	struct DeviceGroupDeviceCreateInfo : InputStructure
	{
		std::uint32_t physicalDeviceCount;
		const PhysicalDevice* physicalDevices;
	};
}
