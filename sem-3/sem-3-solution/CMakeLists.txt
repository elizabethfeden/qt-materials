cmake_minimum_required(VERSION 3.20)
project(sem3_solution)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(sem3_solution main.cpp main_window.h main_window.cpp painters.h painters.cpp resources.qrc)
target_link_libraries(sem3_solution
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )
