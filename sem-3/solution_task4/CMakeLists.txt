cmake_minimum_required(VERSION 3.21)
project(HotGame)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH ~/Qt/6.2.4/gcc_64/lib/cmake)

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(HotGame
        main.cpp
        main_window.cpp
        main_window.h
        resources/resources.qrc
        movable_item.cpp
        movable_item.h
        constants.cpp)
target_link_libraries(HotGame
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )
