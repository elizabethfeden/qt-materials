cmake_minimum_required(VERSION 3.21)
project(sem_3_common)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(main main.cpp main_window.cpp main_window.h paint_widget.cpp paint_widget.h)
target_link_libraries(main
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )

