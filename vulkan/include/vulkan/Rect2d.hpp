#pragma once
#include <vulkan/Extent2d.hpp>
#include <vulkan/Offset2d.hpp>

namespace vk
{
	struct Rect2d
	{
    	Offset2d offset;
    	Extent2d extent;
	};
}
