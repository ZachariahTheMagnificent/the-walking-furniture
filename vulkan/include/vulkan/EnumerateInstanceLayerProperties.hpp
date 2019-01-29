#pragma once
#include <cstdint>
#include <vulkan/API_PTR.hpp>
#include <vulkan/LayerProperties.hpp>
#include <vulkan/Result.hpp>

namespace vk
{
	typedef Result (VKAPI_PTR *EnumerateInstanceLayerProperties)(
		std::uint32_t* pPropertyCount,
		LayerProperties* pProperties);
}
