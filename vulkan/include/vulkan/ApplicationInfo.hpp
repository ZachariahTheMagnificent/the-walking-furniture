#pragma once
#include <cstdint>
#include <vulkan/InputStructure.hpp>

namespace vk
{
	struct ApplicationInfo : InputStructure
	{
		const char* pApplicationName;
		std::uint32_t applicationVersion;
		const char* pEngineName;
		std::uint32_t engineVersion;
		std::uint32_t apiVersion;
	};
}
