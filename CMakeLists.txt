cmake_minimum_required(VERSION 3.10)

project(QuickImGui CXX)

set(QUICK_IMGUI_BACKEND "DX11_WIN32" CACHE STRING "Configure backend that QuickImGui runs upon")
set(CMAKE_CXX_STANDARD 17)

file(GLOB QUICKIMGUI_SOURCES ./src/*.cpp ./external/imgui/*.cpp)
add_library(quick-imgui ${QUICKIMGUI_SOURCES})

target_include_directories(quick-imgui
	PUBLIC ./include ./external/imgui
	PRIVATE ./external/imgui/examples)

if (QUICK_IMGUI_BACKEND STREQUAL "DX11_WIN32")
	target_sources(quick-imgui 
		PRIVATE ./src/backend/backend_dx11_win32.cpp
				./external/imgui/examples/imgui_impl_dx11.cpp
				./external/imgui/examples/imgui_impl_win32.cpp)

	target_link_libraries(quick-imgui
		PRIVATE d3d11)
else()
	message(FATAL_ERROR "unrecognized backend ${QUICK_IMGUI_BACKEND}...")
endif()
