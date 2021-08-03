cmake_minimum_required (VERSION 3.20.0)
project(dd)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/artifacts)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/artifacts)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/artifacts)


if(NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/conan.cmake")
   message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
   file(DOWNLOAD "https://raw.githubusercontent.com/conan-io/cmake-conan/master/conan.cmake"
                  "${CMAKE_CURRENT_SOURCE_DIR}/conan.cmake")
endif()
include(${CMAKE_CURRENT_SOURCE_DIR}/conan.cmake)
conan_cmake_run(CONANFILE ${CMAKE_CURRENT_SOURCE_DIR}/conanfile.txt
                BASIC_SETUP CMAKE_TARGETS
                BUILD missing)


add_subdirectory(teapp)