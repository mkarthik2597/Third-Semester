# SCBuilder version 0.1.6 Cmake file
# Invoke with cmake -G "MSYS Makefiles" ..

cmake_minimum_required(VERSION 3.2.2)
project("reg")

set(SYSTEMC_HOME "C:/SCBuilder//SystemC")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(SCV_HOME "C:/SCBuilder//SCV")
include_directories("C:/Users/Karthik/Desktop/A1/Q8")
include_directories(${SYSTEMC_HOME}/include)
include_directories(${SCV_HOME}/include)

link_directories(${SYSTEMC_HOME}/lib-mingw)
link_directories(${SCV_HOME}/lib-mingw)

add_executable(reg
	"C:/Users/Karthik/Desktop/A1/Q8/main.cpp")

target_link_libraries(reg scv) 				#link the SCV library
target_link_libraries(reg systemc) 			#link the SystemC library
