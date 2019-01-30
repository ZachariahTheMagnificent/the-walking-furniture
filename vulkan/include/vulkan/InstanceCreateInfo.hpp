#pragma once
#include <cstdint>
#include <vulkan/InputStructure.hpp>
#include <vulkan/ApplicationInfo.hpp>
#include <vulkan/InstanceCreateFlags.hpp>

namespace vk
{
	struct InstanceCreateInfo : InputStructure
	{
		constexpr InstanceCreateInfo(
			const ApplicationInfo* applicationInfo,
			std::uint32_t enabledLayerCount,
			const char* const* enabledLayerNames,
			std::uint32_t enabledExtensionCount,
			const char* const* enabledExtensionNames
		) noexcept
		:
		InputStructure{StructureType::instanceCreateInfo},
		flags{},
		applicationInfo{applicationInfo},
		enabledLayerCount{enabledLayerCount},
		enabledLayerNames{enabledLayerNames},
		enabledExtensionCount{enabledExtensionCount},
		enabledExtensionNames{enabledExtensionNames}
		{

		}

		InstanceCreateFlags flags;
		const ApplicationInfo* applicationInfo;
		std::uint32_t enabledLayerCount;
		const char* const* enabledLayerNames;
		std::uint32_t enabledExtensionCount;
		const char* const* enabledExtensionNames;
	};
}
