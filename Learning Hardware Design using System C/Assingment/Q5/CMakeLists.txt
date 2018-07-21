# SCBuilder version 0.1.6 Cmake file
# Invoke with cmake -G "MSYS Makefiles" ..

cmake_minimum_required(VERSION 3.2.2)
project("nbitadder")

set(SYSTEMC_HOME "G:/SCBuilder//SystemC")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(SCV_HOME "G:/SCBuilder//SCV")
include_directories("H:/Academics/SystemC/Assignment/n bit Adder")
include_directories(${SYSTEMC_HOME}/include)
include_directories(${SCV_HOME}/include)

link_directories(${SYSTEMC_HOME}/lib-mingw)
link_directories(${SCV_HOME}/lib-mingw)

add_executable(nbitadder
	"H:/Academics/SystemC/Assignment/n bit Adder/main.cpp")

target_link_libraries(nbitadder scv) 				#link the SCV library
target_link_libraries(nbitadder systemc) 			#link the SystemC library
