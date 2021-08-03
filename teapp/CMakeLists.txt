project(teapp
        VERSION 1.0
        LANGUAGES CXX
)


if(EXISTS ${CMAKE_BINARY_DIR}/conanbuildinfo_multi.cmake)
    include(${CMAKE_BINARY_DIR}/conanbuildinfo_multi.cmake)
else()
    include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
endif()
conan_basic_setup()


file(GLOB my_sources ${PROJECT_SOURCE_DIR}/sources/*.cpp)
file(GLOB my_headers ${PROJECT_SOURCE_DIR}/sources/*.hpp)


add_executable(${PROJECT_NAME} ${my_headers} ${my_sources})
conan_target_link_libraries(${PROJECT_NAME})

# target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

# install(TARGETS ${PROJECT_NAME}
#         EXPORT ${PROJECT_NAME}
#         LIBRARY DESTINATION lib
#         ARCHIVE DESTINATION lib
#         RUNTIME DESTINATION bin
#         INCLUDES DESTINATION include
# )

# install(EXPORT teappTargets
#         FILE teappTargets.cmake
#         NAMESPACE ${PROJECT_NAME}::
#         DESTINATION lib/cmake/${PROJECT_NAME}
# )
