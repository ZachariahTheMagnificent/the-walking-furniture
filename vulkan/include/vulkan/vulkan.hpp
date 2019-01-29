#pragma once
#include <cstdint>
#include <vulkan/ext/ValidationCheck.hpp>
#include <vulkan/ext/ValidationFeatureDisable.hpp>
#include <vulkan/ext/ValidationFeatureEnable.hpp>
#include <vulkan/ext/ValidationFeatures.hpp>
#include <vulkan/ext/ValidationFlags.hpp>
#include <vulkan/khr/PhysicalDeviceIdProperties.hpp>
#include <vulkan/khr/PhysicalDeviceProperties2.hpp>
#include <vulkan/AllocationCallbacks.hpp>
#include <vulkan/API_PTR.hpp>
#include <vulkan/ApplicationInfo.hpp>
#include <vulkan/Bool.hpp>
#include <vulkan/CreateInstance.hpp>
#include <vulkan/DestroyInstance.hpp>
#include <vulkan/Device.hpp>
#include <vulkan/DeviceAddress.hpp>
#include <vulkan/DeviceSize.hpp>
#include <vulkan/EnumerateInstanceExtensionProperties.hpp>
#include <vulkan/EnumerateInstanceLayerProperties.hpp>
#include <vulkan/EnumerateInstanceVersion.hpp>
#include <vulkan/EnumeratePhysicalDevices.hpp>
#include <vulkan/ExtensionProperties.hpp>
#include <vulkan/Extent2d.hpp>
#include <vulkan/Extent3d.hpp>
#include <vulkan/Flag.hpp>
#include <vulkan/GetDeviceProcAddr.hpp>
#include <vulkan/GetInstanceProcAddr.hpp>
#include <vulkan/InputStructure.hpp>
#include <vulkan/Instance.hpp>
#include <vulkan/InstanceCreateFlags.hpp>
#include <vulkan/InstanceCreateInfo.hpp>
#include <vulkan/LayerProperties.hpp>
#include <vulkan/luidSize.hpp>
#include <vulkan/maxDescriptionSize.hpp>
#include <vulkan/maxExtensionNameSize.hpp>
#include <vulkan/maxPhysicalDeviceNameSize.hpp>
#include <vulkan/Offset2d.hpp>
#include <vulkan/Offset3d.hpp>
#include <vulkan/OutputStructure.hpp>
#include <vulkan/PhysicalDevice.hpp>
#include <vulkan/PhysicalDeviceIdProperties.hpp>
#include <vulkan/PhysicalDeviceLimits.hpp>
#include <vulkan/PhysicalDeviceProperties.hpp>
#include <vulkan/PhysicalDeviceProperties2.hpp>
#include <vulkan/PhysicalDeviceSparceProperties.hpp>
#include <vulkan/PhysicalDeviceType.hpp>
#include <vulkan/Rect2d.hpp>
#include <vulkan/Result.hpp>
#include <vulkan/SampleCountFlags.hpp>
#include <vulkan/StructureType.hpp>
#include <vulkan/uuidSize.hpp>
#include <vulkan/VendorId.hpp>
#include <vulkan/version.hpp>
#include <vulkan/VoidFunction.hpp>

namespace vk
{
	typedef void (VKAPI_PTR *GetPhysicalDeviceProperties)(PhysicalDevice physicalDevice, PhysicalDeviceProperties* pProperties);

	typedef void (VKAPI_PTR *GetPhysicalDeviceProperties2)(
		PhysicalDevice physicalDevice,
		PhysicalDeviceProperties2* pProperties);

	typedef void (VKAPI_PTR *GetPhysicalDeviceProperties2KHR)(
		PhysicalDevice physicalDevice,
		PhysicalDeviceProperties2* pProperties);
}
