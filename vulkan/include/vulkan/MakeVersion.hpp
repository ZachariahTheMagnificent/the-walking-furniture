#pragma once
#include <cstdint>

namespace vk
{
	constexpr std::uint32_t MakeVersion(const std::uint32_t major, const std::uint32_t minor, const std::uint32_t patch)
	{
		return major << 22 | minor << 10 | patch;
	}
}
