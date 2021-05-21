file(GLOB_RECURSE srcs CONFIGURE_DEPENDS
    *.cpp
    *.cc
    *.c
)

add_executable(robot_test ${srcs})

target_link_libraries(robot_test
PRIVATE 
    robot
    gtest
    gtest_main
)

add_test(NAME robot_test COMMAND robot_test)
