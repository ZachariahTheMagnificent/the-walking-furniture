#pragma once
#include <cstdint>
#include <vulkan/InputStructure.hpp>

namespace vk
{
	struct ApplicationInfo : InputStructure
	{
		constexpr ApplicationInfo(
			const char* name,
			std::uint32_t version,
			const char* engineName,
			std::uint32_t engineVersion,
			std::uint32_t apiVersion
		) noexcept
		:
		InputStructure{StructureType::applicationInfo},
		name{name},
		version{version},
		engineName{engineName},
		engineVersion{engineVersion},
		apiVersion{apiVersion}
		{

		}

		const char* name;
		std::uint32_t version;
		const char* engineName;
		std::uint32_t engineVersion;
		std::uint32_t apiVersion;
	};
}
