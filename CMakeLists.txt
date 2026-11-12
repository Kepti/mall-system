cmake_minimum_required(VERSION 3.20)

project(mall_system VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(MSVC)
    set(CMAKE_MSVC_RUNTIME_LIBRARY
        "MultiThreaded$<$<CONFIG:Debug>:Debug>")
    add_compile_options(/utf-8)
endif()

add_executable(mall src/main.cpp  "tests/coupon_tests.cpp")

target_include_directories(mall PRIVATE src)

enable_testing()

add_executable(coupon_tests tests/coupon_tests.cpp)

target_include_directories(coupon_tests PRIVATE src)

add_test(NAME coupon_tests COMMAND coupon_tests)