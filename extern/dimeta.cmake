include(ExternalProject)
ExternalProject_Add(dimeta EXCLUDE_FROM_ALL 1
        URL https://github.com/notfoundry/dimeta/archive/master.zip
        TIMEOUT 120
        PREFIX "${CMAKE_CURRENT_BINARY_DIR}/dependencies/dimeta"
#        CONFIGURE_COMMAND "" # Disable configure step
#        BUILD_COMMAND ""     # Disable build step
        INSTALL_COMMAND ""   # Disable install step
        TEST_COMMAND ""      # Disable test step
        UPDATE_COMMAND ""    # Disable source work-tree update
        )
ExternalProject_Get_Property(dimeta SOURCE_DIR)
set(dimeta_INCLUDE_DIR ${SOURCE_DIR}/include)

ExternalProject_Get_Property(dimeta BINARY_DIR)
set(dimeta_DEPENDENCY_INCLUDE_DIR ${BINARY_DIR}/extern/dependencies/kvasir/src/Kvasir/src)

target_include_directories(trimeta INTERFACE ${dimeta_INCLUDE_DIR} ${dimeta_DEPENDENCY_INCLUDE_DIR})
add_dependencies(trimeta dimeta)