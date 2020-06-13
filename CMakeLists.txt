cmake_minimum_required(VERSION 3.8)

project("QAdvancedSpinBox")
set(CPACK_PACKAGE_VERSION "0.0.1")

enable_language(CXX)

include(GNUInstallDirs)
include(CPackComponent)
#find_package(PkgConfig REQUIRED)

set(CMAKE_USE_RELATIVE_PATHS ON)
set(BUILD_SHARED_LIBS ON)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")
include(Hardening)


if(${CMAKE_VERSION} VERSION_GREATER "3.12")
	set(CMAKE_CXX_STANDARD 20)
else()
	if(${CMAKE_VERSION} VERSION_GREATER "3.8")
		set(CMAKE_CXX_STANDARD 17)
	else()
		set(CMAKE_CXX_STANDARD 14)
	endif()
endif()

macro(pass_through_cpack_vars)
	get_cmake_property(cpackVarsToPassthrough VARIABLES)
	foreach(varName ${cpackVarsToPassthrough})
		if(varName MATCHES "^CPACK_")
			set("${varName}" "${${varName}}" PARENT_SCOPE)
		endif()
	endforeach()
endmacro()

set(CMAKE_AUTOMOC ON)
find_package(Qt5Core CONFIG REQUIRED)
find_package(Qt5Widgets CONFIG REQUIRED)


set(Example_dir "${CMAKE_CURRENT_SOURCE_DIR}/example")

set(Source_dir "${CMAKE_CURRENT_SOURCE_DIR}/src")
set(Include_dir "${CMAKE_CURRENT_SOURCE_DIR}/include")
set(Include_subdir "${Include_dir}/QAdvancedSpinBox")

add_subdirectory("${Source_dir}")

set(QAdvancedSpinBox_BUILD_EXAMPLE OFF CACHE BOOL "Build example")

if(QAdvancedSpinBox_BUILD_EXAMPLE)
	add_subdirectory("${Example_dir}")
endif()

set(CPACK_PACKAGE_CHECKSUM "SHA512")
set(CPACK_GENERATOR "DEB")
set(CPACK_DEBIAN_COMPRESSION_TYPE "xz")
option(CPACK_RPM_COMPONENT_INSTALL "Split into multiple rpm packages" ON)
option(CPACK_DEB_COMPONENT_INSTALL "Split into multiple deb packages" ON)
set(CPACK_PACKAGE_VENDOR "Sandro Fadiga")
set(CPACK_PACKAGE_CONTACT "https://github.com/sfadiga/AdvancedSpinBox")
set(CPACK_PACKAGE_HOMEPAGE_URL "https://github.com/sfadiga/AdvancedSpinBox")
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE")
set(CPACK_RESOURCE_FILE_README "${CMAKE_CURRENT_SOURCE_DIR}/README.md")
set(CPACK_PACKAGE_DESCRIPTION_FILE "${CMAKE_CURRENT_SOURCE_DIR}/CPack.Description.txt")

set(CPACK_DEBIAN_PACKAGE_NAME "QAdvancedSpinBox")
set(CPACK_COMPONENTS_GROUPING "IGNORE")

set(CPACK_MONOLITHIC_INSTALL OFF)


include(CPack)
