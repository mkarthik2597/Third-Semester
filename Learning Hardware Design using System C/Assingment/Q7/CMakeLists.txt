# SCBuilder version 0.1.6 Cmake file
# Invoke with cmake -G "MSYS Makefiles" ..

cmake_minimum_required(VERSION 3.2.2)
project("DFlipFlop")

set(SYSTEMC_HOME "G:/SCBuilder//SystemC")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(SCV_HOME "G:/SCBuilder//SCV")
include_directories("H:/Academics/SystemC/Assignment/D_Flip_Flop")
include_directories(${SYSTEMC_HOME}/include)
include_directories(${SCV_HOME}/include)

link_directories(${SYSTEMC_HOME}/lib-mingw)
link_directories(${SCV_HOME}/lib-mingw)

add_executable(DFlipFlop
	"H:/Academics/SystemC/Assignment/D_Flip_Flop/main.cc")

target_link_libraries(DFlipFlop scv) 				#link the SCV library
target_link_libraries(DFlipFlop systemc) 			#link the SystemC library
