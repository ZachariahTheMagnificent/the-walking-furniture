#pragma once

namespace vk::ext
{
	enum class ValidationFeatureDisable
	{
		all = 0,
		shaders = 1,
		thread_safety = 2,
		api_parameters = 3,
		object_lifetimes = 4,
		core_checks = 5,
		unique_handles = 6,
	};
}
