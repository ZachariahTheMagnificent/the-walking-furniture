#pragma once
#include <cstdint>
#include <vulkan/maxExtensionNameSize.hpp>

namespace vk
{
	struct ExtensionProperties
	{
		char name[maxExtensionNameSize];
		std::uint32_t version;
	};
}
