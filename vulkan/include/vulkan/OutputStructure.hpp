#pragma once
#include <vulkan/StructureType.hpp>

namespace vk
{
	struct OutputStructure
	{
		StructureType type;
		OutputStructure* next;
	};
}
