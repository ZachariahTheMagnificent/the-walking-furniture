#pragma once
#include <cstdint>
#include <vulkan/maxExtensionNameSize.hpp>

namespace vk
{
	struct ExtensionProperties
	{
		char extensionName[maxExtensionNameSize];
		std::uint32_t specVersion;
	};
}
