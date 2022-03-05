cmake_minimum_required(VERSION 3.21)
project(Task-3)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(Task-3 main.cpp main_window.cpp main_window.h)
target_link_libraries(Task-3
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )