# CMakeList.txt : CMakeLists for RenderEngineProj::Renderer_Interface

# CMake configuration and settings ****************************************************************
#**************************************************************************************************

cmake_minimum_required(VERSION 3.25)

project(RENDERER_INTERFACE VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Define custom configuration types for Debug, Release, and Release-Dev
set(CMAKE_CONFIGURATION_TYPES "Debug;Release;RelWithDebInfo" CACHE STRING "List of supported build modes." FORCE)

# Define compiler definitions to create OS specific code segments
if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
	add_compile_definitions(TARGET_OS=Windows _WIN_TARGET)
elseif(CMAKE_SYSTEM_NAME STREQUAL "Linux")
	add_compile_definitions(TARGET_OS=Linux _LINUX_TARGET)
elseif(CMAKE_SYSTEM_NAME STREQUAL "Darwin") #MacOS
	add_compile_definitions(TARGET_OS=MacOS _MACOS_TARGET)
endif()

# Make sure CMake exports its compile commands so things like IntelliSense can detect them in editor
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# End CMake configuration and settings ************************************************************
#**************************************************************************************************

# Target Creation *********************************************************************************
#**************************************************************************************************

# Create CMake reference to this source directory, can be used in CMake files that include this target
set(RendererInterface_SOURCE_DIR $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>)

# Create the Renderer Interface library
add_library(RendererInterface INTERFACE)

target_include_directories(RendererInterface INTERFACE 
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> 
 	$<INSTALL_INTERFACE:include> # This is used when the library is installed
)

set_target_properties(RendererInterface PROPERTIES 
	VERSION ${PROJECT_VERSION} 
	SOVERSION ${PROJECT_VERSION_MAJOR}
)

# End Target Creation *****************************************************************************
#**************************************************************************************************

# Installation and Packing Configuration **********************************************************
#**************************************************************************************************

# Install the library, header files, and config version file
install(
	TARGETS RendererInterface 
	EXPORT RendererInterfaceTargets
)
install(
	EXPORT RendererInterfaceTargets 
	FILE RendererInterfaceTargets.cmake 
	DESTINATION lib/cmake/RendererInterface
)
install(
	FILES "${CMAKE_CURRENT_BINARY_DIR}/RendererInterfaceConfigVersion.cmake" 
	DESTINATION lib/cmake/RendererInterface
)
install(
	DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/ DESTINATION include
)

# Generate and install the package version config file
include(CMakePackageConfigHelpers)
write_basic_package_version_file(
	"${CMAKE_CURRENT_BINARY_DIR}/RendererInterfaceConfigVersion.cmake"
	VERSION ${PROJECT_VERSION}
	COMPATIBILITY AnyNewerVersion
)
install(FILES "${CMAKE_CURRENT_BINARY_DIR}/RendererInterfaceConfigVersion.cmake" 
	DESTINATION lib/cmake/RendererInterface
)

# Create and install the package config file
export(EXPORT RendererInterfaceTargets 
	FILE "${CMAKE_CURRENT_BINARY_DIR}/RendererInterfaceTargets.cmake" 
 	NAMESPACE RendererInterface::
)
configure_file(RendererInterfaceConfig.cmake.in 
	"${CMAKE_CURRENT_BINARY_DIR}/RendererInterfaceConfig.cmake" @ONLY
)
install(FILES 
	"${CMAKE_CURRENT_BINARY_DIR}/RendererInterfaceConfig.cmake" 
 	DESTINATION lib/cmake/RendererInterface
)

# End Installation and Packing Configuration ******************************************************
#**************************************************************************************************
