message(STATUS "Added the following executables:")

add_executable(hello hello.cpp)
target_link_libraries(hello util)
message(STATUS "  hello")

add_executable(DCMotorTest DCmotor_test.cpp)
target_link_libraries(DCMotorTest util)
target_link_libraries(DCMotorTest structure)
target_link_libraries(DCMotorTest BlackLib)
message(STATUS "  DCMotorTest")

add_executable(TestRun test_run.cpp)
target_link_libraries(TestRun util)
target_link_libraries(TestRun structure)
target_link_libraries(TestRun BlackLib)
message(STATUS "  TestRun")
