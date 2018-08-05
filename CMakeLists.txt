cmake_minimum_required(VERSION 3.0)
project(openglFramework)


set(BUILD_SHARED_LIBS FALSE)

if(UNIX)
	#set(CMAKE_CXX_FLAGS "-Wall -std=c++0x -pedantic -O2 -g -pg")
	#set(CMAKE_CXX_FLAGS "-Wall -Wstrict-aliasing -std=c++0x -O2")

	set(CMAKE_CXX_FLAGS "-Wall -std=c++11 -O2")

	# valgrind --leak-check=full ./demo
	# ./demo # creates cmon.out
	# gprof demo gmon.out > analysis.txt
	#set(CMAKE_CXX_FLAGS "-Wall -pg -std=c++11")
endif(UNIX)


if(WIN32)
	# suppress pedantic warnings
	add_definitions( "/W1 /D_CRT_SECURE_NO_WARNINGS /wd4514 /nologo" )
endif(WIN32)

find_package(OpenGL REQUIRED)

add_subdirectory("externals")
include_directories(
  ${CMAKE_SOURCE_DIR}/externals/glfw-3.2.1/include/GLFW
  ${CMAKE_SOURCE_DIR}/externals/glad/include
  ${CMAKE_SOURCE_DIR}/externals/glm-0.9.9.0
  ${CMAKE_SOURCE_DIR}/externals
  ${CMAKE_SOURCE_DIR}/engine
  ${CMAKE_SOURCE_DIR}/.
)

link_directories(
  ${CMAKE_SOURCE_DIR}/externals/glfw-3.2.1/src
  ${CMAKE_SOURCE_DIR}/externals/glad
  ${CMAKE_SOURCE_DIR}/externals
  ${CMAKE_SOURCE_DIR}/engine
)

set(LIBS
  ${OPENGL_LIBRARY}
  engine
  glfw
	soil
  GLAD
)

add_definitions(
	-DTW_STATIC
	-DTW_NO_LIB_PRAGMA
	-DTW_NO_DIRECT3D
	-DGLEW_STATIC
	-D_CRT_SECURE_NO_WARNINGS
)

add_library(engine
	engine/input.cpp
	engine/input.h
  engine/renderer.cpp
  engine/renderer.h
  engine/mesh.cpp
  engine/mesh.h
	engine/texture.cpp
	engine/texture.h
	engine/utils.hpp
  engine/vector3.cpp
  engine/vector3.h
)
add_executable(game
  game/main.cpp
)

target_link_libraries(game
  ${LIBS}
)

#copy shaders
file(
	COPY ${CMAKE_SOURCE_DIR}/engine/shaders
	DESTINATION ${CMAKE_BINARY_DIR}
)

file(
	COPY ${CMAKE_SOURCE_DIR}/engine/assets
	DESTINATION ${CMAKE_BINARY_DIR}
)
