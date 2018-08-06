if(MSVC AND NOT "${MSVC_VERSION}" LESS 1400)
	add_definitions( "/MP" )
endif()

#GLFW_321
add_subdirectory(glfw-3.2.1)
#Assimp
add_subdirectory(assimp-4.1.0)

include_directories(
    glfw-3.2.1/include/GLFW
    glew-2.1.0/include/
	${Assimp_SOURCE_DIR}/include
    ${Assimp_SOURCE_DIR}/code
)

if(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
set(OPENGL_LIBRARY
	${OPENGL_LIBRARY}
	-lGL -lGLU -lXrandr -lXext -lX11 -lrt
	${CMAKE_DL_LIBS}
	${GLFW_LIBRARIES}
)
elseif(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
set(OPENGL_LIBRARY
	${OPENGL_LIBRARY}
	${CMAKE_DL_LIBS}
	${GLFW_LIBRARIES}
)
endif(${CMAKE_SYSTEM_NAME} MATCHES "Linux")

#GLAD
add_library(GLAD STATIC
	glad/include/glad.c
	glad/include/glad.h
	glad/include/khrplatform.h
)

target_link_libraries(GLAD
	${OPENGL_LIBRARY}
	${EXTRA_LIBS}
)

add_library(soil
	soil/image_DXT.c
	soil/image_DXT.h
	soil/image_helper.c
	soil/image_helper.h
	soil/SOIL.c
	soil/SOIL.c
	soil/stb_image_aug.c
	soil/stb_image_aug.h
	soil/stbi_DDS_aug_c.h
	soil/stbi_DDS_aug.h
)

target_link_libraries(soil
	GLAD
)
