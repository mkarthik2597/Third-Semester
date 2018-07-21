# SCBuilder version 0.1.6 Cmake file
# Invoke with cmake -G "MSYS Makefiles" ..

cmake_minimum_required(VERSION 3.2.2)
project("interconnect")

set(SYSTEMC_HOME "C:/SCBuilder//SystemC")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
include_directories("C:/Users/Karthik/Desktop/SystemC/Interconnect")
include_directories(${SYSTEMC_HOME}/include)

link_directories(${SYSTEMC_HOME}/lib-mingw)

add_executable(interconnect
	"C:/Users/Karthik/Desktop/SystemC/Interconnect/main.cpp")

target_link_libraries(interconnect systemc) 			#link the SystemC library
