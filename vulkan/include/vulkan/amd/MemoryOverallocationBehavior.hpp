#pragma once
#include <vulkan/amd/MemoryOverallocationBehavior.hpp>
#include <vulkan/InputStructure.hpp>

namespace vk::amd
{
	struct DeviceMemoryOverallocationCreateInfo : InputStructure
	{
		MemoryOverallocationBehavior behavior;
	};
}
