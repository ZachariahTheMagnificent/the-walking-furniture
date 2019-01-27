#pragma once

#if defined _WIN32
	#define VKAPI_PTR __stdcall
#else
	#define VKAPI_PTR
#endif
