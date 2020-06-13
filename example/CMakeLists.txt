set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

file(GLOB_RECURSE SRCFILES "${CMAKE_CURRENT_SOURCE_DIR}/*.c" "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
add_executable(QAdvancedSpinBox_example "${SRCFILES}")
target_link_libraries(QAdvancedSpinBox_example QAdvancedSpinBox Qt5::Core Qt5::Gui Qt5::Widgets)
target_include_directories(QAdvancedSpinBox_example PUBLIC "${Include_dir}")
harden(QAdvancedSpinBox_example)

pass_through_cpack_vars()
