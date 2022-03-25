cmake_minimum_required(VERSION 3.21)
project(sem-4)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(sem-4
        main.cpp
        controller.cpp
        abstract_view.cpp
        models.cpp
        views.cpp
        abstract_view.cpp
        )

target_link_libraries(sem-4
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )

