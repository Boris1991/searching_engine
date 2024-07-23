cmake_minimum_required(VERSION 3.1.0)
project(search_engine)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(SOURCES
    main.cpp
    src/ConverterJSON.cpp
    include/ConverterJSON.h
    qml.qrc  
)

set(JSON_BuildTests OFF CACHE INTERNAL "")

find_package(Qt5 COMPONENTS Core Quick Multimedia QuickControls2 Widgets Qml REQUIRED)

include(FetchContent)
FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.11.3/json.tar.xz)
FetchContent_MakeAvailable(json)

add_executable(search_engine ${SOURCES})


target_link_libraries(search_engine Qt5::Core Qt5::Quick Qt5::Multimedia Qt5::Qml nlohmann_json::nlohmann_json)

target_include_directories(search_engine PUBLIC include src json)
