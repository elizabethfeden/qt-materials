cmake_minimum_required(VERSION 3.20)
project(task6)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(task6 main.cpp main_window.cpp)
target_link_libraries(task6
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )
