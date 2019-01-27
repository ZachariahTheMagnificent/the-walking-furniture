#pragma once
#include <cstdint>
#include <vulkan/InputStructure.hpp>
#include <vulkan/ext/ValidationCheck.hpp>

namespace vk::ext
{
	struct ValidationFlags : InputStructure
	{
		std::uint32_t disabledValidationCheckCount;
		const ValidationCheck* pDisabledValidationChecks;
	};
}
