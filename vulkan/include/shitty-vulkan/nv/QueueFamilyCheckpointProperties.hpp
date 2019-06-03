#pragma once
#include <vulkan/OutputStructure.hpp>
#include <vulkan/PipelineStageFlags.hpp>

namespace vk::nv
{
	struct QueueFamilyCheckpointProperties : OutputStructure
	{
		PipelineStageFlags checkpointExecutionStageMask;
	};
}
