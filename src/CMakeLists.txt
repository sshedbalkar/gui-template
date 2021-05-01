
find_package(PkgConfig REQUIRED)
pkg_search_module(GLFW REQUIRED glfw3)

find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIR})

find_package(GLUT REQUIRED)
include_directories(${GLUT_INCLUDE_DIR})

# Add source files
set(SOURCE_FILES Application.cpp Application.h)

# message("CXX id: ${CMAKE_CXX_COMPILER_ID}")
# If we build for windows systems, we also include the resource file
# containing the manifest, icon and other resources
if(WIN32)
    set(SOURCE_FILES ${SOURCE_FILES} sample.rc)
endif(WIN32)

# the above paths and defines will be used in this build
add_executable(${CMAKE_PROJECT_NAME} WIN32 ${SOURCE_FILES})
# set(RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin/$<CONFIG>)

set_target_properties(${CMAKE_PROJECT_NAME}
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin/$<CONFIG>/lib"
    LIBRARY_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin/$<CONFIG>/lib"
    RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin/$<CONFIG>/bin"
)

# starget_compile_options(${CMAKE_PROJECT_NAME} PRIVATE $<$<CXX_COMPILER_ID:AppleClang,Clang>:-framework OpenGL> )
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE ${GLFW_LIBRARIES} ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES}) 

target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE ${GLFW_INCLUDE_DIRS} ${CMAKE_CURRENT_SOURCE_DIR}/include)
# Add to forty to the wxWidgets libraries. These are
# set for  by the find script. Other needed libraries can be added here

target_link_directories(${CMAKE_PROJECT_NAME} PRIVATE ${GLFW_LIBRARY_DIRS})

# copy the executable to the bin directory
# add_custom_command(TARGET ${CMAKE_PROJECT_NAME} POST_BUILD
#     COMMAND ${CMAKE_COMMAND} -E copy_if_different 
#         $<TARGET_FILE:${CMAKE_PROJECT_NAME}>
#         "${PROJECT_SOURCE_DIR}/bin/$<CONFIG>" VERBATIM)