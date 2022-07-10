cmake_minimum_required(VERSION 3.21)
project(sem8)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

if (APPLE)
    set(CMAKE_PREFIX_PATH "~/Qt/6.2.3/macos")
elseif(UNIX)
    set(CMAKE_PREFIX_PATH "~/Qt/6.2.3/gcc_64")
endif()

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        LinguistTools # required package for qt_create_translation cmake function
        REQUIRED)

# define a variable containing the list of source files or directories
# in order to reuse it in qt_create_translation and add_executable
set(PROJECT_SOURCES
        main.cpp
        main_window.cpp
        main_window.h)

# define a variable for i18n files just for convenience
set(TRANSLATIONS
        translations/by.ts
        translations/de.ts
        translations/en.ts)

qt_create_translation(QM_FILES ${PROJECT_SOURCES} ${TRANSLATIONS})
# here comes the tricky part :)
# CMake will generate .qm files via the function above IN BUILD DIRECTORY (e.g. cmake-build-debug, cmake-build-release)
# but resources.qrc is located IN SOURCE DIRECTORY and is gonna search for qm files relative to its own directory.
# Well, of course, we can write "cmake_build_debug" in resources.qrc, but it really smells...
# Instead we are gonna just copy resources.qrc to build directory, so it could find generated .qm files
configure_file(resources.qrc ${CMAKE_BINARY_DIR} COPYONLY)

# we add a dependency on QM_FILES to trigger rebuild on translation files change
# and a dependency on resource file located in build directory, not the original one
add_executable(sem8 ${PROJECT_SOURCES} ${QM_FILES} ${CMAKE_BINARY_DIR}/resources.qrc)
target_link_libraries(sem8
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )

