#pragma once
#include <cstdint>
#include <vulkan/InputStructure.hpp>
#include <vulkan/ext/ValidationFeatureDisable.hpp>
#include <vulkan/ext/ValidationFeatureEnable.hpp>

namespace vk::ext
{
	struct ValidationFeatures : InputStructure
	{
		std::uint32_t enabledValidationFeatureCount;
		const ValidationFeatureEnable* enabledValidationFeatures;
		std::uint32_t disabledValidationFeatureCount;
		const ValidationFeatureDisable* disabledValidationFeatures;
	};
}
