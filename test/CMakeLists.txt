set(test_files
        main.cpp
        test_memory.cpp)

add_executable(trimeta_test ${test_files})
target_link_libraries(trimeta_test PUBLIC trimeta)
target_compile_definitions(trimeta_test PRIVATE DIMETA_CONSISTENCY_CHECKS)
target_compile_options(trimeta_test PRIVATE "-ftemplate-backtrace-limit=0" "-ftemplate-depth=100000")

enable_testing()
add_test(NAME trimeta_test COMMAND trimeta_test)