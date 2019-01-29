#pragma once
#include <cstdint>
#include <vulkan/API_PTR.hpp>
#include <vulkan/ExtensionProperties.hpp>
#include <vulkan/Result.hpp>

namespace vk
{
	typedef Result (VKAPI_PTR *EnumerateInstanceExtensionProperties)(
		const char* pLayerName,
		std::uint32_t* pPropertyCount,
		ExtensionProperties* pProperties);
}