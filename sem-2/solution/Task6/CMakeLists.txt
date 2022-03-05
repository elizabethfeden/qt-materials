cmake_minimum_required(VERSION 3.20)
project(mainwindow_demo)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(qt-test main.cpp main_window.cpp)
target_link_libraries(qt-test
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )
