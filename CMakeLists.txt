cmake_minimum_required(VERSION 3.14)
project(trimeta)

set(CMAKE_CXX_STANDARD 17)

set(header_files
        "include/trimeta/detail/generic_primitives.hpp"
        "include/trimeta/unit_primitives.hpp"
        "include/trimeta/clock.hpp")

set(include_files ${header_files})

add_library(trimeta INTERFACE)
target_sources(trimeta INTERFACE ${include_files})

target_include_directories(trimeta INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>)

add_subdirectory(extern EXCLUDE_FROM_ALL)

option(TRIMETA_CONSISTENCY_CHECKS "whether or not to enable internal state validation" ON)
if (TRIMETA_CONSISTENCY_CHECKS)
    target_compile_definitions(trimeta INTERFACE TRIMETA_CONSISTENCY_CHECKS)
endif()

option(DIMETA_ASM_BUILD_TESTS "build tests" ON)
if (DIMETA_ASM_BUILD_TESTS)
    add_subdirectory(test)
endif()