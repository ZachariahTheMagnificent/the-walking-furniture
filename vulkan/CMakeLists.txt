cmake_minimum_required(VERSION 3.11.0)
project(vulkan)

add_library(vulkan INTERFACE)
target_compile_features(vulkan INTERFACE cxx_std_17)
target_include_directories(vulkan INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_sources(vulkan
	INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/include/vulkan/vk_icd.h"
	INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/include/vulkan/vk_layer.h"
	INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/include/vulkan/vk_platform.h"
	INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/include/vulkan/vk_sdk_platform.h"
	INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/include/vulkan/vulkan_android.h"
	INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/include/vulkan/vulkan_core.h"
	INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/include/vulkan/vulkan_fuchsia.h"
	INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/include/vulkan/vulkan_ggp.h"
	INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/include/vulkan/vulkan_ios.h"
	INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/include/vulkan/vulkan_macos.h"
	INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/include/vulkan/vulkan_metal.h"
	INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/include/vulkan/vulkan_vi.h"
	INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/include/vulkan/vulkan_wayland.h"
	INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/include/vulkan/vulkan_win32.h"
	INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/include/vulkan/vulkan_xcb.h"
	INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/include/vulkan/vulkan_xlib_xrandr.h"
	INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/include/vulkan/vulkan_xlib.h"
	INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/include/vulkan/vulkan.h"
	INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/include/vulkan/vulkan.hpp"
)
