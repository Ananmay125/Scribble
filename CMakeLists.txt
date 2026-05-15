# CMakeList.txt
cmake_minimum_required (VERSION 3.8)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project ("scribble")

add_subdirectory(libs/glfw)

# Add source to this project's executable.
add_executable (scribble 
    "src/scribble.cpp" 
    "src/scribble.h" 
    "src/graphics/window.h" 
    "src/graphics/window.cpp" 
    "libs/glad/src/glad.c"
)

target_include_directories(scribble PRIVATE 
    libs/glfw/include
    libs/glad/include   
    libs      
    libs/imgui
    libs/imgui/backends
)

target_link_libraries(scribble PRIVATE 
    glfw 
    opengl32 
)

add_custom_command(TARGET scribble POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    "${CMAKE_CURRENT_SOURCE_DIR}/shaders"
    "$<TARGET_FILE_DIR:scribble>/shaders"
)

add_custom_command(TARGET scribble POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    "${CMAKE_CURRENT_SOURCE_DIR}/resources"
    "$<TARGET_FILE_DIR:scribble>/resources"
)

install(TARGETS scribble DESTINATION .)
install(DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/shaders/" DESTINATION "shaders")
install(DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/resources/" DESTINATION "resources")
