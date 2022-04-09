cmake_minimum_required(VERSION 3.21)
project(geobebra)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(geobebra
        main.cpp
        main_window.cpp
        paint_widget.cpp
        plot_descriptor_widget.cpp
        )

target_link_libraries(geobebra
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )