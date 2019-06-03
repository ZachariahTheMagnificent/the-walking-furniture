#pragma once
#include <vulkan/OutputStructure.hpp>
#include <vulkan/QueueFamilyProperties.hpp>

namespace vk
{
	struct QueueFamilyProperties2 : OutputStructure, QueueFamilyProperties
	{
	};
}
