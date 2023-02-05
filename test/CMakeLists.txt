cmake_minimum_required(VERSION 3.0.0)

set(This tests)

#set(HEADERS //////)
set(SOURCES
     tests.cpp
     ../main.cpp
)

add_executable(${This} ${SOURCES})

set_target_properties(${This} PROPERTIES LINKER_LANGUAGE CXX)

target_link_libraries(${This} PUBLIC 
    gtest_main
    tempStabilizer
) 

add_test(
    NAME ${This}
    COMMAND ${This}
)