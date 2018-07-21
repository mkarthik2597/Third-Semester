# SCBuilder version 0.1.6 Cmake file
# Invoke with cmake -G "MSYS Makefiles" ..

cmake_minimum_required(VERSION 3.2.2)
project("siso")

set(SYSTEMC_HOME "C:/SCBuilder//SystemC")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(SCV_HOME "C:/SCBuilder//SCV")
include_directories("C:/Users/Karthik/Desktop/32bitsiso")
include_directories(${SYSTEMC_HOME}/include)
include_directories(${SCV_HOME}/include)

link_directories(${SYSTEMC_HOME}/lib-mingw)
link_directories(${SCV_HOME}/lib-mingw)

add_executable(siso
	"C:/Users/Karthik/Desktop/32bitsiso/main.cpp")

target_link_libraries(siso scv) 				#link the SCV library
target_link_libraries(siso systemc) 			#link the SystemC library
