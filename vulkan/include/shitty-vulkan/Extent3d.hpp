#pragma once
#include <cstdint>

namespace vk
{
	struct Extent3d
	{
		std::uint32_t width;
		std::uint32_t height;
		std::uint32_t depth;
	};
}
