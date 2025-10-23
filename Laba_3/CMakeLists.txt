cmake_minimum_required(VERSION 3.10)
project(laba_3)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.15.0
  TLS_VERIFY false
)

FetchContent_MakeAvailable(googletest)

add_library(${CMAKE_PROJECT_NAME}_lib
    src/Points.cpp
    src/Figure.cpp
    src/FigureArray.cpp
    src/Rhombus.cpp
    src/Pentagon.cpp
    src/Hexagon.cpp
)

target_include_directories(${CMAKE_PROJECT_NAME}_lib PUBLIC include)

add_executable(${CMAKE_PROJECT_NAME}_src main.cpp)
target_link_libraries(${CMAKE_PROJECT_NAME}_src ${CMAKE_PROJECT_NAME}_lib)

add_executable(tests
    tests/test_main.cpp
    tests/test_points.cpp
    tests/test_rhombus.cpp
    tests/test_pentagon.cpp
    tests/test_hexagon.cpp
    tests/test_figure_array.cpp
)

target_include_directories(tests PRIVATE include)
target_link_libraries(tests ${CMAKE_PROJECT_NAME}_lib gtest_main)

enable_testing()
add_test(NAME AllTests COMMAND tests)