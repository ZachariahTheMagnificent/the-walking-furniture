#pragma once
#include <vulkan/Bool.hpp>

namespace vk
{
	struct PhysicalDeviceSparseProperties
	{
		Bool residencyStandard2DBlockShape;
		Bool residencyStandard2DMultisampleBlockShape;
		Bool residencyStandard3DBlockShape;
		Bool residencyAlignedMipSize;
		Bool residencyNonResidentStrict;
	};
}
