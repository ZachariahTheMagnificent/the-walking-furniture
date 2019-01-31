#pragma once

namespace vk::ext
{
	enum class ValidationFeatureDisable
	{
		all = 0,
		shaders = 1,
		threadSafety = 2,
		apiParameters = 3,
		objectLifetimes = 4,
		coreChecks = 5,
		uniqueHandles = 6,
	};
}
