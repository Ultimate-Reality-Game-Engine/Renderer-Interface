# CMakeList.txt : CMakeLists for RenderEngineProj::Renderer_Interface

# CMake configuration and settings ****************************************************************
#**************************************************************************************************

cmake_minimum_required(VERSION 3.25)

project(RENDERER_INTERFACE VERSION 1.0.0)

set(RENDERER_INTERFACE_VERSION ${PROJECT_VERSION})
set(RENDERER_INTERFACE_VERSION_MAJOR ${PROJECT_VERION_MAJOR})

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Define custom configuration types for Debug, Release, and Release-Dev
set(CMAKE_CONFIGURATION_TYPES "Debug;Release;RelWithDebInfo" CACHE STRING "List of supported build modes." FORCE)

# End CMake configuration and settings ************************************************************
#**************************************************************************************************

# Target Creation *********************************************************************************
#**************************************************************************************************

# Create CMake reference to this source directory, can be used in CMake files that include this target
set(RendererInterface_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})

# Create the Renderer Interface library
add_library(RendererInterface INTERFACE)

# End Target Creation *****************************************************************************
#**************************************************************************************************

# Installation and Packing Configuration **********************************************************
#**************************************************************************************************

# Set up version file for Interface
include(CMakePackageConfigHelpers)
write_basic_package_version_file(
	"${CMAKE_CURRENT_BINARY_DIR}/RendererInterfaceConfigVersion.cmake"
	VERSION ${RENDERER_INTERFACE_VERSION}
	COMPATIBILITY AnyNewerVersion
)

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

# End Installation and Packing Configuration ******************************************************
#**************************************************************************************************