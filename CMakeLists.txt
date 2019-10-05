cmake_minimum_required(VERSION 3.14)
project(trimeta)

set(CMAKE_CXX_STANDARD 17)

set(alu_files
        include/trimeta/alu/adder.hpp
        include/trimeta/alu/alu.hpp)

set(detail_files
        include/trimeta/detail/generic_primitives.hpp)

set(lib_files
        include/trimeta/lib/and.hpp
        include/trimeta/lib/decoder.hpp
        include/trimeta/lib/mux.hpp
        include/trimeta/lib/not.hpp
        include/trimeta/lib/or.hpp)

set(memory_files
        include/trimeta/memory/dff.hpp
        include/trimeta/memory/register.hpp
        include/trimeta/memory/ram.hpp)

set(include_files ${alu_files} ${detail_files} ${lib_files} ${memory_files})

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