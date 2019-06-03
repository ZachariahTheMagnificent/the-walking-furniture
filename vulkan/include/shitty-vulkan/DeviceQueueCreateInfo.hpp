#pragma once
#include <cstdint>
#include <vulkan/DeviceQueueCreateFlags.hpp>
#include <vulkan/InputStructure.hpp>

namespace vk
{
	struct DeviceQueueCreateInfo : InputStructure
	{
		DeviceQueueCreateFlags flags;
		std::uint32_t queueFamilyIndex;
		std::uint32_t queueCount;
		const float* queuePriorities;
	};
}
