#pragma once
#include <cstdint>

namespace vk::khr
{
	struct ConformanceVersion
	{
		std::uint8_t major;
		std::uint8_t minor;
		std::uint8_t subminor;
		std::uint8_t patch;
	};
}
