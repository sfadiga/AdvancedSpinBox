set(CMAKE_AUTOMOC ON)

file(GLOB_RECURSE SRCFILES "${CMAKE_CURRENT_SOURCE_DIR}/*.c" "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
file(GLOB_RECURSE HDRFILES "${CMAKE_CURRENT_SOURCE_DIR}/*.h" "${CMAKE_CURRENT_SOURCE_DIR}/*.hpp")
file(GLOB_RECURSE PUBLIC_HDRFILES "${Include_subdir}/*.h" "${Include_subdir}/*.hpp")
qt5_wrap_cpp(SRCFILES ${HDRFILES} ${PUBLIC_HDRFILES} TARGET QAdvancedSpinBox)

add_library(QAdvancedSpinBox SHARED "${SRCFILES}")
target_include_directories(QAdvancedSpinBox PUBLIC "${Include_dir}")
target_link_libraries(QAdvancedSpinBox Qt5::Core Qt5::Widgets)
set_property(TARGET QAdvancedSpinBox PROPERTY CXX_STANDARD 20)
harden(QAdvancedSpinBox)

install(TARGETS "QAdvancedSpinBox"
	LIBRARY
	COMPONENT "lib"
	ARCHIVE
	COMPONENT "dev"
)

install(DIRECTORY ${Include_subdir}
	DESTINATION
	"${CMAKE_INSTALL_FULL_INCLUDEDIR}"
	COMPONENT "dev"
)

#_pkg_set_path_internal()
#set(PKG_CONFIG_PATH "$ENV{PKG_CONFIG_PATH}")
#message(STATUS "PKG_CONFIG_PATH from env ${PKG_CONFIG_PATH}")
#string(REPLACE ":" ";"  PKG_CONFIG_PATH)
#list(GET PKG_CONFIG_PATH 0 PKG_CONFIG_PATH)
#

set(PKG_CONFIG_PATH "${CMAKE_INSTALL_FULL_LIBDIR}/pkgconfig")
message(STATUS "PKG_CONFIG_PATH ${PKG_CONFIG_PATH}")


set(PC_FILE_NAME "libQAdvancedSpinBox.pc")
set(PC_TEMP_NAME "${CMAKE_CURRENT_BINARY_DIR}/${PC_FILE_NAME}")
configure_file("${CMAKE_CURRENT_SOURCE_DIR}/${PC_FILE_NAME}.in" "${PC_TEMP_NAME}")
install(FILES "${PC_TEMP_NAME}"
	DESTINATION
		"${PKG_CONFIG_PATH}"
	COMPONENT "dev"
)

set(CPACK_DEBIAN_LIB_PACKAGE_NAME "libQAdvancedSpinBox")
set(CPACK_RPM_LIB_PACKAGE_NAME "libQAdvancedSpinBox")
set(CPACK_DEBIAN_LIB_PACKAGE_DEPENDS "libqt${Qt5Core_VERSION_MAJOR}core${Qt5Core_VERSION_MAJOR}a, libqt${Qt5Widgets_VERSION_MAJOR}widgets${Qt5Widgets_VERSION_MAJOR}")

set(CPACK_DEBIAN_DEV_PACKAGE_NAME "${CPACK_DEBIAN_LIB_PACKAGE_NAME}-dev")
set(CPACK_RPM_DEV_PACKAGE_NAME "${CPACK_RPM_LIB_PACKAGE_NAME}-devel")
set(CPACK_DEBIAN_DEV_PACKAGE_DEPENDS "${CPACK_DEBIAN_LIB_PACKAGE_NAME}, qtbase${Qt5Core_VERSION_MAJOR}-dev")

pass_through_cpack_vars()
