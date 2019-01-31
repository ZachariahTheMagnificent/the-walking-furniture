#pragma once
#include <cstdint>
#include <vulkan/maxExtensionNameSize.hpp>
#include <vulkan/maxDescriptionSize.hpp>

namespace vk
{
	struct LayerProperties
	{
		char name[maxExtensionNameSize];
		std::uint32_t specVersion;
		std::uint32_t version;
		char description[maxDescriptionSize];
	};
}
