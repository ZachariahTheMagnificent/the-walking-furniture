#pragma once
#include <vulkan/amd/DeviceMemoryOverallocationCreateInfo.hpp>
#include <vulkan/amd/MemoryOverallocationBehavior.hpp>
#include <vulkan/ext/ValidationCheck.hpp>
#include <vulkan/ext/ValidationFeatureDisable.hpp>
#include <vulkan/ext/ValidationFeatureEnable.hpp>
#include <vulkan/ext/ValidationFeatures.hpp>
#include <vulkan/ext/ValidationFlags.hpp>
#include <vulkan/khr/ConformanceVersion.hpp>
#include <vulkan/khr/DeviceGroupDeviceCreateInfo.hpp>
#include <vulkan/khr/DriverId.hpp>
#include <vulkan/khr/EnumeratePhysicalDeviceGroups.hpp>
#include <vulkan/khr/GetPhysicalDeviceProperties2.hpp>
#include <vulkan/khr/GetPhysicalDeviceProperties2.hpp>
#include <vulkan/khr/maxDriverInfoSize.hpp>
#include <vulkan/khr/maxDriverNameSize.hpp>
#include <vulkan/khr/PhysicalDeviceDriverProperties.hpp>
#include <vulkan/khr/PhysicalDeviceGroupProperties.hpp>
#include <vulkan/khr/PhysicalDeviceIdProperties.hpp>
#include <vulkan/khr/PhysicalDeviceProperties2.hpp>
#include <vulkan/khr/QueueFamilyProperties2.hpp>
#include <vulkan/nv/QueueFamilyCheckpointProperties.hpp>
#include <vulkan/AllocationCallbacks.hpp>
#include <vulkan/API_PTR.hpp>
#include <vulkan/ApplicationInfo.hpp>
#include <vulkan/Bool.hpp>
#include <vulkan/CreateDevice.hpp>
#include <vulkan/CreateInstance.hpp>
#include <vulkan/DestroyDevice.hpp>
#include <vulkan/DestroyInstance.hpp>
#include <vulkan/Device.hpp>
#include <vulkan/DeviceAddress.hpp>
#include <vulkan/DeviceCreateFlags.hpp>
#include <vulkan/DeviceCreateInfo.hpp>
#include <vulkan/DeviceGroupDeviceCreateInfo.hpp>
#include <vulkan/DeviceSize.hpp>
#include <vulkan/DeviceWaitIdle.hpp>
#include <vulkan/EnumerateDeviceExtensionProperties.hpp>
#include <vulkan/EnumerateInstanceExtensionProperties.hpp>
#include <vulkan/EnumerateInstanceLayerProperties.hpp>
#include <vulkan/EnumerateInstanceVersion.hpp>
#include <vulkan/EnumeratePhysicalDeviceGroups.hpp>
#include <vulkan/EnumeratePhysicalDevices.hpp>
#include <vulkan/ExtensionProperties.hpp>
#include <vulkan/Extent2d.hpp>
#include <vulkan/Extent3d.hpp>
#include <vulkan/Flags.hpp>
#include <vulkan/GetDeviceProcAddr.hpp>
#include <vulkan/GetInstanceProcAddr.hpp>
#include <vulkan/GetPhysicalDeviceProperties.hpp>
#include <vulkan/GetPhysicalDeviceProperties2.hpp>
#include <vulkan/GetPhysicalDeviceQueueFamilyProperties.hpp>
#include <vulkan/GetPhysicalDeviceQueueFamilyProperties2.hpp>
#include <vulkan/InputStructure.hpp>
#include <vulkan/Instance.hpp>
#include <vulkan/InstanceCreateFlags.hpp>
#include <vulkan/InstanceCreateInfo.hpp>
#include <vulkan/LayerProperties.hpp>
#include <vulkan/luidSize.hpp>
#include <vulkan/MakeVersion.hpp>
#include <vulkan/maxDescriptionSize.hpp>
#include <vulkan/maxDeviceGroupSize.hpp>
#include <vulkan/maxExtensionNameSize.hpp>
#include <vulkan/maxPhysicalDeviceNameSize.hpp>
#include <vulkan/Offset2d.hpp>
#include <vulkan/Offset3d.hpp>
#include <vulkan/OutputStructure.hpp>
#include <vulkan/PhysicalDevice.hpp>
#include <vulkan/PhysicalDeviceFeatures.hpp>
#include <vulkan/PhysicalDeviceGroupProperties.hpp>
#include <vulkan/PhysicalDeviceIdProperties.hpp>
#include <vulkan/PhysicalDeviceLimits.hpp>
#include <vulkan/PhysicalDeviceProperties.hpp>
#include <vulkan/PhysicalDeviceProperties2.hpp>
#include <vulkan/PhysicalDeviceSparceProperties.hpp>
#include <vulkan/PhysicalDeviceType.hpp>
#include <vulkan/PipelineStageFlags.hpp>
#include <vulkan/PrintableVersion.hpp>
#include <vulkan/QueueFamilyProperties.hpp>
#include <vulkan/QueueFamilyProperties2.hpp>
#include <vulkan/QueueFlagBits.hpp>
#include <vulkan/QueueFlags.hpp>
#include <vulkan/Rect2d.hpp>
#include <vulkan/Result.hpp>
#include <vulkan/SampleCountFlags.hpp>
#include <vulkan/StructureType.hpp>
#include <vulkan/uuidSize.hpp>
#include <vulkan/VendorId.hpp>
#include <vulkan/version.hpp>
#include <vulkan/VoidFunction.hpp>

constexpr auto is64bit = sizeof(void*) == 8;

#if !defined VULKAN_HPP_TYPESAFE_CONVERSION
#define VULKAN_HPP_TYPESAFE_CONVERSION 1
#endif

namespace
#if defined VULKAN_HPP_NAMESPACE
VULKAN_HPP_NAMESPACE
#else
vk
#endif
{
}
