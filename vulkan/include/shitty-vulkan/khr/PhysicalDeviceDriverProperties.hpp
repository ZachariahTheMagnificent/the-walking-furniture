#pragma once
#include <vulkan/khr/ConformanceVersion.hpp>
#include <vulkan/khr/DriverId.hpp>
#include <vulkan/khr/maxDriverInfoSize.hpp>
#include <vulkan/khr/maxDriverNameSize.hpp>
#include <vulkan/OutputStructure.hpp>

namespace vk::khr
{
	struct PhysicalDeviceDriverProperties : OutputStructure
	{
		DriverId id;
		char name[maxDriverNameSize];
		char info[maxDriverInfoSize];
		ConformanceVersion conformanceVersion;
	};
}
