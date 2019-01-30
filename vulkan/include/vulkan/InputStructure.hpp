#pragma once
#include <vulkan/StructureType.hpp>

namespace vk
{
	struct InputStructure
	{
		constexpr InputStructure(const StructureType type) noexcept
		:
		type{type},
		next{nullptr}
		{

		}

		StructureType type;
		const InputStructure* next;
	};
}
