#pragma once
#include <vulkan/StructureType.hpp>

namespace vk
{
	struct InputStructure
	{
		StructureType type;
		const InputStructure* next;
	};
}
