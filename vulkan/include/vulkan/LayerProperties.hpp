#pragma once
#include <cstdint>
#include <vulkan/maxExtensionNameSize.hpp>
#include <vulkan/maxDescriptionSize.hpp>

namespace vk
{
	struct LayerProperties
	{
		char layerName[maxExtensionNameSize];
		std::uint32_t specVersion;
		std::uint32_t implementationVersion;
		char description[maxDescriptionSize];
	};
}
