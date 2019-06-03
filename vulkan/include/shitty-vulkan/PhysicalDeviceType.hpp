#pragma once

namespace vk
{
	enum class PhysicalDeviceType
	{
		other = 0,
		integratedGpu = 1,
		discreteGpu = 2,
		virtualGpu = 3,
		cpu = 4,
	};
}
