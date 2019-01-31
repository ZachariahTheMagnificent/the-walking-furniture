#pragma once
#include <vulkan/OutputStructure.hpp>
#include <vulkan/PhysicalDeviceProperties.hpp>

namespace vk
{
	struct PhysicalDeviceProperties2 : OutputStructure, PhysicalDeviceProperties
	{
	};
}
