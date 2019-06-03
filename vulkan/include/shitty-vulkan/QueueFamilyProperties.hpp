#pragma once
#include <cstdint>
#include <vulkan/Extent3d.hpp>
#include <vulkan/QueueFlags.hpp>

namespace vk
{
	struct QueueFamilyProperties
	{
		QueueFlags queueFlags;
		std::uint32_t queueCount;
		std::uint32_t timestampValidBits;
		Extent3d minImageTransferGranularity;
	};
}
