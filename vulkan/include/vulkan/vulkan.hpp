#pragma once
#include <cstdint>
#include <vulkan/ext/ValidationCheck.hpp>
#include <vulkan/ext/ValidationFeatureDisable.hpp>
#include <vulkan/ext/ValidationFeatureEnable.hpp>
#include <vulkan/ext/ValidationFeatures.hpp>
#include <vulkan/ext/ValidationFlags.hpp>
#include <vulkan/khr/PhysicalDeviceProperties2.hpp>
#include <vulkan/API_PTR.hpp>
#include <vulkan/ApplicationInfo.hpp>
#include <vulkan/Bool.hpp>
#include <vulkan/Device.hpp>
#include <vulkan/DeviceAddress.hpp>
#include <vulkan/DeviceSize.hpp>
#include <vulkan/ExtensionProperties.hpp>
#include <vulkan/Extent2d.hpp>
#include <vulkan/Extent3d.hpp>
#include <vulkan/Flag.hpp>
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
	using InstanceHandle = struct Instance*;
	struct AllocationCallbacks;

	typedef VoidFunction (VKAPI_PTR *GetInstanceProcAddr)(InstanceHandle handle, const char* name);

	typedef Result (VKAPI_PTR *EnumerateInstanceVersion)(std::uint32_t* output);
	typedef Result (VKAPI_PTR *EnumerateInstanceExtensionProperties)(
    const char* pLayerName,
    std::uint32_t* pPropertyCount,
    ExtensionProperties* pProperties);
	typedef Result (VKAPI_PTR *EnumerateInstanceLayerProperties)(
    uint32_t*                                   pPropertyCount,
    LayerProperties*                          pProperties);

	typedef Result (VKAPI_PTR *CreateInstance)(const InstanceCreateInfo* info, const AllocationCallbacks* allocator, InstanceHandle* output);
	typedef void (VKAPI_PTR *DestroyInstance)(InstanceHandle instance, const AllocationCallbacks* pAllocator);

	using DeviceHandle = struct Device*;
	using PhysicalDeviceHandle = struct PhysicalDevice*;
	typedef PhysicalDeviceIdProperties VkPhysicalDeviceIDPropertiesKHR;

	typedef VoidFunction (VKAPI_PTR *GetDeviceProcAddr)(DeviceHandle handle, const char* name);
	typedef Result (VKAPI_PTR *EnumeratePhysicalDevices)(InstanceHandle instance, std::uint32_t* pPhysicalDeviceCount, PhysicalDeviceHandle* pPhysicalDevices);

	typedef void (VKAPI_PTR *GetPhysicalDeviceProperties)(PhysicalDeviceHandle physicalDevice, PhysicalDeviceProperties* pProperties);

	typedef void (VKAPI_PTR *GetPhysicalDeviceProperties2)(
    PhysicalDeviceHandle physicalDevice,
    PhysicalDeviceProperties2* pProperties);

	typedef void (VKAPI_PTR *GetPhysicalDeviceProperties2KHR)(
    PhysicalDeviceHandle physicalDevice,
    PhysicalDeviceProperties2* pProperties);
}
