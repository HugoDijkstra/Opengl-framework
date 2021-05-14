# Install script for directory: /home/hugo/Projects/Opengl-framework/externals/assimp-5.0.1/code

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "0")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libassimp.so.5.0.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libassimp.so.5"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHECK
           FILE "${file}"
           RPATH "")
    endif()
  endforeach()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES
    "/home/hugo/Projects/Opengl-framework/externals/assimp-5.0.1/lib/libassimp.so.5.0.0"
    "/home/hugo/Projects/Opengl-framework/externals/assimp-5.0.1/lib/libassimp.so.5"
    )
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libassimp.so.5.0.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libassimp.so.5"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      if(CMAKE_INSTALL_DO_STRIP)
        execute_process(COMMAND "/usr/bin/strip" "${file}")
      endif()
    endif()
  endforeach()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libassimp.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libassimp.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libassimp.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/hugo/Projects/Opengl-framework/externals/assimp-5.0.1/lib/libassimp.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libassimp.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libassimp.so")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libassimp.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xassimp-devx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/assimp" TYPE FILE FILES
    "/home/hugo/Projects/Opengl-framework/externals/assimp-5.0.1/code/../include/assimp/anim.h"
    "/home/hugo/Projects/Opengl-framework/externals/assimp-5.0.1/code/../include/assimp/aabb.h"
    "/home/hugo/Projects/Opengl-framework/externals/assimp-5.0.1/code/../include/assimp/ai_assert.h"
    "/home/hugo/Projects/Opengl-framework/externals/assimp-5.0.1/code/../include/assimp/camera.h"
    "/home/hugo/Projects/Opengl-framework/externals/assimp-5.0.1/code/../include/assimp/color4.h"
    "/home/hugo/Projects/Opengl-framework/externals/assimp-5.0.1/code/../include/assimp/color4.inl"
    "/home/hugo/Projects/Opengl-framework/externals/assimp-5.0.1/code/../include/assimp/config.h"
    "/home/hugo/Projects/Opengl-framework/externals/assimp-5.0.1/code/../include/assimp/defs.h"
    "/home/hugo/Projects/Opengl-framework/externals/assimp-5.0.1/code/../include/assimp/Defines.h"
    "/home/hugo/Projects/Opengl-framework/externals/assimp-5.0.1/code/../include/assimp/cfileio.h"
    "/home/hugo/Projects/Opengl-framework/externals/assimp-5.0.1/code/../include/assimp/light.h"
    "/home/hugo/Projects/Opengl-framework/externals/assimp-5.0.1/code/../include/assimp/material.h"
    "/home/hugo/Projects/Opengl-framework/externals/assimp-5.0.1/code/../include/assimp/material.inl"
    "/home/hugo/Projects/Opengl-framework/externals/assimp-5.0.1/code/../include/assimp/matrix3x3.h"
    "/home/hugo/Projects/Opengl-framework/externals/assimp-5.0.1/code/../include/assimp/matrix3x3.inl"
    "/home/hugo/Projects/Opengl-framework/externals/assimp-5.0.1/code/../include/assimp/matrix4x4.h"
    "/home/hugo/Projects/Opengl-framework/externals/assimp-5.0.1/code/../include/assimp/matrix4x4.inl"
    "/home/hugo/Projects/Opengl-framework/externals/assimp-5.0.1/code/../include/assimp/mesh.h"
    "/home/hugo/Projects/Opengl-framework/externals/assimp-5.0.1/code/../include/assimp/pbrmaterial.h"
    "/home/hugo/Projects/Opengl-framework/externals/assimp-5.0.1/code/../include/assimp/postprocess.h"
    "/home/hugo/Projects/Opengl-framework/externals/assimp-5.0.1/code/../include/assimp/quaternion.h"
    "/home/hugo/Projects/Opengl-framework/externals/assimp-5.0.1/code/../include/assimp/quaternion.inl"
    "/home/hugo/Projects/Opengl-framework/externals/assimp-5.0.1/code/../include/assimp/scene.h"
    "/home/hugo/Projects/Opengl-framework/externals/assimp-5.0.1/code/../include/assimp/metadata.h"
    "/home/hugo/Projects/Opengl-framework/externals/assimp-5.0.1/code/../include/assimp/texture.h"
    "/home/hugo/Projects/Opengl-framework/externals/assimp-5.0.1/code/../include/assimp/types.h"
    "/home/hugo/Projects/Opengl-framework/externals/assimp-5.0.1/code/../include/assimp/vector2.h"
    "/home/hugo/Projects/Opengl-framework/externals/assimp-5.0.1/code/../include/assimp/vector2.inl"
    "/home/hugo/Projects/Opengl-framework/externals/assimp-5.0.1/code/../include/assimp/vector3.h"
    "/home/hugo/Projects/Opengl-framework/externals/assimp-5.0.1/code/../include/assimp/vector3.inl"
    "/home/hugo/Projects/Opengl-framework/externals/assimp-5.0.1/code/../include/assimp/version.h"
    "/home/hugo/Projects/Opengl-framework/externals/assimp-5.0.1/code/../include/assimp/cimport.h"
    "/home/hugo/Projects/Opengl-framework/externals/assimp-5.0.1/code/../include/assimp/importerdesc.h"
    "/home/hugo/Projects/Opengl-framework/externals/assimp-5.0.1/code/../include/assimp/Importer.hpp"
    "/home/hugo/Projects/Opengl-framework/externals/assimp-5.0.1/code/../include/assimp/DefaultLogger.hpp"
    "/home/hugo/Projects/Opengl-framework/externals/assimp-5.0.1/code/../include/assimp/ProgressHandler.hpp"
    "/home/hugo/Projects/Opengl-framework/externals/assimp-5.0.1/code/../include/assimp/IOStream.hpp"
    "/home/hugo/Projects/Opengl-framework/externals/assimp-5.0.1/code/../include/assimp/IOSystem.hpp"
    "/home/hugo/Projects/Opengl-framework/externals/assimp-5.0.1/code/../include/assimp/Logger.hpp"
    "/home/hugo/Projects/Opengl-framework/externals/assimp-5.0.1/code/../include/assimp/LogStream.hpp"
    "/home/hugo/Projects/Opengl-framework/externals/assimp-5.0.1/code/../include/assimp/NullLogger.hpp"
    "/home/hugo/Projects/Opengl-framework/externals/assimp-5.0.1/code/../include/assimp/cexport.h"
    "/home/hugo/Projects/Opengl-framework/externals/assimp-5.0.1/code/../include/assimp/Exporter.hpp"
    "/home/hugo/Projects/Opengl-framework/externals/assimp-5.0.1/code/../include/assimp/DefaultIOStream.h"
    "/home/hugo/Projects/Opengl-framework/externals/assimp-5.0.1/code/../include/assimp/DefaultIOSystem.h"
    "/home/hugo/Projects/Opengl-framework/externals/assimp-5.0.1/code/../include/assimp/ZipArchiveIOSystem.h"
    "/home/hugo/Projects/Opengl-framework/externals/assimp-5.0.1/code/../include/assimp/SceneCombiner.h"
    "/home/hugo/Projects/Opengl-framework/externals/assimp-5.0.1/code/../include/assimp/fast_atof.h"
    "/home/hugo/Projects/Opengl-framework/externals/assimp-5.0.1/code/../include/assimp/qnan.h"
    "/home/hugo/Projects/Opengl-framework/externals/assimp-5.0.1/code/../include/assimp/BaseImporter.h"
    "/home/hugo/Projects/Opengl-framework/externals/assimp-5.0.1/code/../include/assimp/Hash.h"
    "/home/hugo/Projects/Opengl-framework/externals/assimp-5.0.1/code/../include/assimp/MemoryIOWrapper.h"
    "/home/hugo/Projects/Opengl-framework/externals/assimp-5.0.1/code/../include/assimp/ParsingUtils.h"
    "/home/hugo/Projects/Opengl-framework/externals/assimp-5.0.1/code/../include/assimp/StreamReader.h"
    "/home/hugo/Projects/Opengl-framework/externals/assimp-5.0.1/code/../include/assimp/StreamWriter.h"
    "/home/hugo/Projects/Opengl-framework/externals/assimp-5.0.1/code/../include/assimp/StringComparison.h"
    "/home/hugo/Projects/Opengl-framework/externals/assimp-5.0.1/code/../include/assimp/StringUtils.h"
    "/home/hugo/Projects/Opengl-framework/externals/assimp-5.0.1/code/../include/assimp/SGSpatialSort.h"
    "/home/hugo/Projects/Opengl-framework/externals/assimp-5.0.1/code/../include/assimp/GenericProperty.h"
    "/home/hugo/Projects/Opengl-framework/externals/assimp-5.0.1/code/../include/assimp/SpatialSort.h"
    "/home/hugo/Projects/Opengl-framework/externals/assimp-5.0.1/code/../include/assimp/SkeletonMeshBuilder.h"
    "/home/hugo/Projects/Opengl-framework/externals/assimp-5.0.1/code/../include/assimp/SmoothingGroups.h"
    "/home/hugo/Projects/Opengl-framework/externals/assimp-5.0.1/code/../include/assimp/SmoothingGroups.inl"
    "/home/hugo/Projects/Opengl-framework/externals/assimp-5.0.1/code/../include/assimp/StandardShapes.h"
    "/home/hugo/Projects/Opengl-framework/externals/assimp-5.0.1/code/../include/assimp/RemoveComments.h"
    "/home/hugo/Projects/Opengl-framework/externals/assimp-5.0.1/code/../include/assimp/Subdivision.h"
    "/home/hugo/Projects/Opengl-framework/externals/assimp-5.0.1/code/../include/assimp/Vertex.h"
    "/home/hugo/Projects/Opengl-framework/externals/assimp-5.0.1/code/../include/assimp/LineSplitter.h"
    "/home/hugo/Projects/Opengl-framework/externals/assimp-5.0.1/code/../include/assimp/TinyFormatter.h"
    "/home/hugo/Projects/Opengl-framework/externals/assimp-5.0.1/code/../include/assimp/Profiler.h"
    "/home/hugo/Projects/Opengl-framework/externals/assimp-5.0.1/code/../include/assimp/LogAux.h"
    "/home/hugo/Projects/Opengl-framework/externals/assimp-5.0.1/code/../include/assimp/Bitmap.h"
    "/home/hugo/Projects/Opengl-framework/externals/assimp-5.0.1/code/../include/assimp/XMLTools.h"
    "/home/hugo/Projects/Opengl-framework/externals/assimp-5.0.1/code/../include/assimp/IOStreamBuffer.h"
    "/home/hugo/Projects/Opengl-framework/externals/assimp-5.0.1/code/../include/assimp/CreateAnimMesh.h"
    "/home/hugo/Projects/Opengl-framework/externals/assimp-5.0.1/code/../include/assimp/irrXMLWrapper.h"
    "/home/hugo/Projects/Opengl-framework/externals/assimp-5.0.1/code/../include/assimp/BlobIOSystem.h"
    "/home/hugo/Projects/Opengl-framework/externals/assimp-5.0.1/code/../include/assimp/MathFunctions.h"
    "/home/hugo/Projects/Opengl-framework/externals/assimp-5.0.1/code/../include/assimp/Macros.h"
    "/home/hugo/Projects/Opengl-framework/externals/assimp-5.0.1/code/../include/assimp/Exceptional.h"
    "/home/hugo/Projects/Opengl-framework/externals/assimp-5.0.1/code/../include/assimp/ByteSwapper.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xassimp-devx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/assimp/Compiler" TYPE FILE FILES
    "/home/hugo/Projects/Opengl-framework/externals/assimp-5.0.1/code/../include/assimp/Compiler/pushpack1.h"
    "/home/hugo/Projects/Opengl-framework/externals/assimp-5.0.1/code/../include/assimp/Compiler/poppack1.h"
    "/home/hugo/Projects/Opengl-framework/externals/assimp-5.0.1/code/../include/assimp/Compiler/pstdint.h"
    )
endif()

