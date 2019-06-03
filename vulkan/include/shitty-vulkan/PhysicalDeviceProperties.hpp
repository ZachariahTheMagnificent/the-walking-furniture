#pragma once
#include <cstdint>
#include <vulkan/maxPhysicalDeviceNameSize.hpp>
#include <vulkan/PhysicalDeviceLimits.hpp>
#include <vulkan/PhysicalDeviceSparceProperties.hpp>
#include <vulkan/PhysicalDeviceType.hpp>
#include <vulkan/uuidSize.hpp>

namespace vk
{
	struct PhysicalDeviceProperties
	{
		std::uint32_t apiVersion;
		std::uint32_t driverVersion;
		std::uint32_t vendorId;
		std::uint32_t deviceId;
		PhysicalDeviceType deviceType;
		char deviceName[maxPhysicalDeviceNameSize];
		std::uint8_t pipelineCacheUuid[uuidSize];
		PhysicalDeviceLimits limits;
		PhysicalDeviceSparseProperties sparseProperties;
	};
}
