#pragma once
#include <vulkan/API_PTR.hpp>
#include <vulkan/Device.hpp>
#include <vulkan/Result.hpp>

namespace vk
{
	typedef Result (VKAPI_PTR *DeviceWaitIdle)(Device device);
}
