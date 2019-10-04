set(alu_files
        ../include/trimeta/alu/adder.hpp
        ../include/trimeta/alu/alu.hpp)

set(basic_files
        ../include/trimeta/lib/not.hpp
        ../include/trimeta/lib/and.hpp
        ../include/trimeta/lib/or.hpp
        ../include/trimeta/lib/decoder.hpp
        ../include/trimeta/lib/mux.hpp)

set(test_files
        main.cpp
        test_adder.cpp)

add_executable(trimeta_test ${test_files} ${alu_files} ${basic_files})
target_link_libraries(trimeta_test PUBLIC trimeta)
target_compile_definitions(trimeta_test PRIVATE DIMETA_CONSISTENCY_CHECKS)
target_compile_options(trimeta_test PRIVATE "-ftemplate-backtrace-limit=0" "-ftemplate-depth=100000")

enable_testing()
add_test(NAME trimeta_test COMMAND trimeta_test)