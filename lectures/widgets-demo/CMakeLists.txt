cmake_minimum_required(VERSION 3.21)
project(widget_demo)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(widget_demo main.cpp main_window.cpp main_window.h)
target_link_libraries(widget_demo
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )

