#pragma once
#include <cstdint>
#include <vulkan/InputStructure.hpp>
#include <vulkan/ApplicationInfo.hpp>
#include <vulkan/InstanceCreateFlags.hpp>

namespace vk
{
	struct InstanceCreateInfo : InputStructure
	{
		InstanceCreateFlags flags;
		const ApplicationInfo* pApplicationInfo;
		std::uint32_t enabledLayerCount;
		const char* const* ppEnabledLayerNames;
		std::uint32_t enabledExtensionCount;
		const char* const* ppEnabledExtensionNames;
	};
}
