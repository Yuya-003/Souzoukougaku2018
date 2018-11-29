message(STATUS "Added the following executables:")

add_executable(hello hello.cpp)
target_link_libraries(hello util)
message(STATUS "  hello")

add_executable(DCMotorTest DCmotor_test.cpp)
target_link_libraries(DCMotorTest util)
message(STATUS "  DCMotorTest")
