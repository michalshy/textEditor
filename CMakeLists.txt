cmake_minimum_required(VERSION 3.27)
project(textEditor VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets Core Gui)
qt_standard_project_setup()

qt_add_executable(textEditor
        src/main.cpp
        src/MainWindow.cpp
        src/MainWindow.hpp)

target_link_libraries(textEditor PRIVATE
        Qt6::Widgets
        Qt6::Gui
        Qt6::Core)

set_target_properties(textEditor PROPERTIES
        WIN32_EXECUTABLE ON
        MACOSX_BUNDLE ON)
