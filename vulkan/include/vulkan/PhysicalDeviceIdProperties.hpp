#pragma once
#include <cstdint>
#include <vulkan/Bool.hpp>
#include <vulkan/luidSize.hpp>
#include <vulkan/OutputStructure.hpp>
#include <vulkan/uuidSize.hpp>

namespace vk
{
	struct PhysicalDeviceIdProperties : OutputStructure
	{
		std::uint8_t deviceUUID[uuidSize];
		std::uint8_t driverUUID[uuidSize];
		std::uint8_t deviceLUID[luidSize];
		std::uint32_t deviceNodeMask;
		Bool deviceLUIDValid;
	};
}
