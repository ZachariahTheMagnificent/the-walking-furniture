#pragma once
#include <cstdint>
#include <vulkan/API_PTR.hpp>
#include <vulkan/Result.hpp>

namespace vk
{
	typedef Result (VKAPI_PTR *EnumerateInstanceVersion)(std::uint32_t* version);
}
