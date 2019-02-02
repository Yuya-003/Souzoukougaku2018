message(STATUS "Added the following executables:")

add_executable(hello hello.cpp)
target_link_libraries(hello util)
message(STATUS "  hello")

add_executable(DCMotorTest DCmotor_test.cpp)
target_link_libraries(DCMotorTest util)
target_link_libraries(DCMotorTest structure)
target_link_libraries(DCMotorTest BlackLib)
message(STATUS "  DCMotorTest")

add_executable(LineTracerTest line_tracer_test.cpp)
target_link_libraries(LineTracerTest util)
target_link_libraries(LineTracerTest structure)
target_link_libraries(LineTracerTest BlackLib)
message(STATUS "  LineTracerTest")

add_executable(TestRun test_run.cpp)
target_link_libraries(TestRun util)
target_link_libraries(TestRun structure)
target_link_libraries(TestRun BlackLib)
message(STATUS "  TestRun")

add_executable(UltrasonicSensorTest ultrasonic_sensor_test.cpp)
target_link_libraries(UltrasonicSensorTest util)
target_link_libraries(UltrasonicSensorTest structure)
target_link_libraries(UltrasonicSensorTest BlackLib)
message(STATUS "  UltrasonicSensorTest")

#add_executable(TestRun2 test_run_2.cpp)
#target_link_libraries(TestRun2 util)
#target_link_libraries(TestRun2 structure)
#target_link_libraries(TestRun2 BlackLib)
#message(STATUS "  TestRun2")

add_executable(TcpTest tcp_test.cpp)
target_link_libraries(TcpTest util)
target_link_libraries(TcpTest structure)

message(STATUS "  TcpTest")
