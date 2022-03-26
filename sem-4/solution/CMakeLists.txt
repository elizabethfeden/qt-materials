cmake_minimum_required(VERSION 3.20.2)
project(solution)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(solution
        main.cpp
        controller.cpp
        abstract_view.cpp
        models.cpp
        views.cpp
        abstract_view.cpp
        resources.qrc
        )

target_link_libraries(solution
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )

