cmake_minimum_required(VERSION 3.5)
project(IndustrialControllerEmulator)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 COMPONENTS Widgets REQUIRED)

set(HEADERS
    src/UI/mainwindow.h
    src/UI/circlewidget.h
    src/Core/controlleremulator.h
)

set(SOURCES
    src/main.cpp
    src/UI/mainwindow.cpp
    src/UI/circlewidget.cpp
    src/Core/controlleremulator.cpp
)

set(UI_SOURCES src/UI/mainWindow.ui)

qt_wrap_ui(UI_HEADERS ${UI_SOURCES})

add_executable(IndustrialControllerEmulator
    ${UI_HEADERS}
    ${HEADERS}
    ${SOURCES}
)

include_directories(
    ${CMAKE_CURRENT_BINARY_DIR}
)

target_link_libraries(IndustrialControllerEmulator PRIVATE Qt6::Widgets)
target_include_directories(IndustrialControllerEmulator PRIVATE src)
