#pragma once

namespace vk
{
	enum class Result
	{
		success = 0,
		notReady = 1,
		timeout = 2,
		eventSet = 3,
		eventReset = 4,
		incomplete = 5,
		outOfHostMemory = -1,
		outOfDeviceMemory = -2,
		initializationFailed = -3,
		deviceLost = -4,
		memoryMapFailed = -5,
		layerNotPresent = -6,
		extensionNotPresent = -7,
		featureNotPresent = -8,
		incompatibleDriver = -9,
		tooManyObjects = -10,
		formatNotSupported = -11,
		fragmentedPool = -12,
		outOfMemory = -1000069000,
		invalidExternalHandle = -1000072003,
		surfaceLostKhr = -1000000000,
		nativeWindowInUseKhr = -1000000001,
		suboptimalKhr = 1000001003,
		outOfDateKhr = -1000001004,
		incompatibleDisplayKhr = -1000003001,
		validationFailedExt = -1000011001,
		invalidShaderNv = -1000012000,
		invalidDrmFormatModifierPlaneLayoutExt = -1000158000,
		fragmentationExt = -1000161000,
		notPermittedExt = -1000174001,
		invalidDeviceAddressExt = -1000244000,
		outOfMemoryKhr = outOfMemory,
		invalidExternalHandleKhr = invalidExternalHandle,
	};
}
