#pragma once
#include <vulkan/API_PTR.hpp>
#include <vulkan/Device.hpp>
#include <vulkan/VoidFunction.hpp>

namespace vk
{
	typedef VoidFunction (VKAPI_PTR *GetDeviceProcAddr)(Device handle, const char* name);
}
