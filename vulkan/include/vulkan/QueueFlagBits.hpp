#pragma once

namespace vk
{
	enum QueueFlagBits
	{
		graphics = 0x00000001,
		compute = 0x00000002,
		transfer = 0x00000004,
		sparceBinding = 0x00000008,
		protectedMemory = 0x00000010,
	};
}
