cmake_minimum_required(VERSION 3.10)

project(QuickImGui CXX)

#set(QUICK_IMGUI_BACKEND "DX11_WIN32" CACHE STRING "Configure backend that QuickImGui runs upon")
set(QUICK_IMGUI_BACKEND "GLFW" CACHE STRING "Configure backend that QuickImGui runs upon")
set(CMAKE_CXX_STANDARD 17)

if (MSVC)
	add_compile_options(/std:c++latest)
endif()

file(GLOB QUICKIMGUI_HEADERS inlucde/*.h)
file(GLOB IMGUI_SOURCES external/imgui/*.cpp)
add_library(quick-imgui STATIC)

target_sources(quick-imgui PRIVATE ${QUICKIMGUI_HEADERS} ${IMGUI_SOURCES})

target_include_directories(quick-imgui
	PUBLIC ./include 
		   ./external/imgui
	PRIVATE ./src
			./external/imgui/examples)

if (QUICK_IMGUI_BACKEND STREQUAL "DX11_WIN32")
	target_sources(quick-imgui 
		PRIVATE ./src/backend_dx11_win32.cpp
				./external/imgui/examples/imgui_impl_dx11.cpp
				./external/imgui/examples/imgui_impl_win32.cpp)

	target_link_libraries(quick-imgui
		PRIVATE d3d11)
elseif(QUICK_IMGUI_BACKEND STREQUAL "GLFW")
	target_sources(quick-imgui
		PRIVATE ./src/backend_gl3_glfw.cpp
				./external/imgui/examples/imgui_impl_opengl3.cpp
				./external/imgui/examples/imgui_impl_glfw.cpp)

	find_package(glfw3 CONFIG REQUIRED)

	target_link_libraries(quick-imgui
		PRIVATE glfw)
else()
	message(FATAL_ERROR "unrecognized backend ${QUICK_IMGUI_BACKEND}...")
endif()
