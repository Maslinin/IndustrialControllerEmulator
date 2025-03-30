cmake_minimum_required(VERSION 3.5)
project(IndustrialControllerEmulator)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 COMPONENTS Widgets REQUIRED)

file(GLOB HEADERS src/**/*.h)
file(GLOB SOURCES src/*.cpp src/**/*.cpp)
file(GLOB UI_SOURCES src/UI/*.ui)

add_executable(IndustrialControllerEmulator WIN32
    ${UI_HEADERS}
    ${HEADERS}
    ${SOURCES}
)

target_link_libraries(IndustrialControllerEmulator PRIVATE Qt6::Widgets)

target_include_directories(IndustrialControllerEmulator PRIVATE 
    ${CMAKE_CURRENT_BINARY_DIR}
    ${CMAKE_SOURCE_DIR}
)

if(WIN32)
    find_program(WINDEPLOYQT_EXECUTABLE windeployqt HINTS "${Qt_DIR}/bin")
    if(WINDEPLOYQT_EXECUTABLE)
        add_custom_command(TARGET IndustrialControllerEmulator POST_BUILD
            COMMAND ${WINDEPLOYQT_EXECUTABLE} $<TARGET_FILE:IndustrialControllerEmulator>
        )
    endif()
endif()
