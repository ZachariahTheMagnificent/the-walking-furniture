#pragma once
#include <vulkan/API_PTR.hpp>
#include <vulkan/Instance.hpp>
#include <vulkan/VoidFunction.hpp>

namespace vk
{
	typedef VoidFunction (VKAPI_PTR *GetInstanceProcAddr)(Instance instance, const char* name);
}
