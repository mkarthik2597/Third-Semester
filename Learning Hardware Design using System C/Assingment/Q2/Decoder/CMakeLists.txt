# SCBuilder version 0.1.6 Cmake file
# Invoke with cmake -G "MSYS Makefiles" ..

cmake_minimum_required(VERSION 3.2.2)
project("decoder")

set(SYSTEMC_HOME "C:/SCBuilder//SystemC")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
include_directories("C:/Users/Karthik/Desktop/A1/Q2/Decoder")
include_directories(${SYSTEMC_HOME}/include)

link_directories(${SYSTEMC_HOME}/lib-mingw)

add_executable(decoder
	"C:/Users/Karthik/Desktop/A1/Q2/Decoder/main.cpp")

target_link_libraries(decoder systemc) 			#link the SystemC library
