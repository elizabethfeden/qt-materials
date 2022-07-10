cmake_minimum_required(VERSION 3.21)
project(task_2_Kalosha)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_PREFIX_PATH "~/Qt/6.2.4/macos/lib/cmake")
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 COMPONENTS Core Gui Widgets REQUIRED)

add_executable(task_2_Kalosha
        main.cpp
        widget.cpp
        widget.h
        )
target_link_libraries(task_2_Kalosha Qt6::Core Qt6::Gui Qt6::Widgets)