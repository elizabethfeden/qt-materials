cmake_minimum_required(VERSION 3.21)
project(sem8)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "/home/adamenko/Qt/6.2.3/gcc_64/")

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(sem8 main.cpp main_window.cpp main_window.h resources.qrc)
target_link_libraries(sem8
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )

