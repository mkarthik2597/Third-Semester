# SCBuilder version 0.1.6 Cmake file
# Invoke with cmake -G "MSYS Makefiles" ..

cmake_minimum_required(VERSION 3.2.2)
project("halfAdder")

set(SYSTEMC_HOME "G:/SCBuilder//SystemC")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(SCV_HOME "G:/SCBuilder//SCV")
include_directories("H:/Academics/SystemC/Assignment/HalfAdder")
include_directories(${SYSTEMC_HOME}/include)
include_directories(${SCV_HOME}/include)

link_directories(${SYSTEMC_HOME}/lib-mingw)
link_directories(${SCV_HOME}/lib-mingw)

add_executable(halfAdder
	"H:/Academics/SystemC/Assignment/HalfAdder/main.cpp")

target_link_libraries(halfAdder scv) 				#link the SCV library
target_link_libraries(halfAdder systemc) 			#link the SystemC library
