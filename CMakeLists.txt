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
FetchContent_Declare(
    json
    URL https://github.com/nlohmann/json/releases/download/v3.11.3/json.tar.xz
)
FetchContent_MakeAvailable(json)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
FetchContent_MakeAvailable(googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

enable_testing()

add_executable(search_engine ${SOURCES})

target_link_libraries(search_engine
    Qt5::Core
    Qt5::Quick
    Qt5::Multimedia
    Qt5::Qml
    nlohmann_json::nlohmann_json
)

target_include_directories(search_engine PUBLIC include src json)

# Поиск и компиляция тестов
file(GLOB TEST_SOURCES "test/*.cpp")
add_executable(run_tests ${TEST_SOURCES})

# Линковка тестов с GoogleTest
target_link_libraries(run_tests
    gtest_main
    Qt5::Core
    Qt5::Quick
    Qt5::Multimedia
    Qt5::Qml
    nlohmann_json::nlohmann_json
)

# Добавление тестов
add_test(NAME run_tests COMMAND run_tests)
