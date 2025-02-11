cmake_minimum_required(VERSION 3.28)

if(NOT DEFINED(${CMAKE_BUILD_TYPE}))
    set(CMAKE_BUILD_TYPE "Debug" CACHE STRING "Debug")
endif()

if(${CMAKE_BUILD_TYPE} MATCHES "Debug")
    if(${CMAKE_GENERATOR} MATCHES "MinGW Makefiles")
        set(ENV{VCPKG_DEFAULT_TRIPLET} "x64-mingw-dynamic") 
        set(ENV{VCPKG_DEFAULT_HOST_TRIPLET} "x64-mingw-dynamic")
        set(VCPKG_TARGET_TRIPLET "x64-mingw-dynamic" CACHE STRING "x64-mingw-dynamic") 
    endif()
	
else()
    if(${CMAKE_GENERATOR} MATCHES "MinGW Makefiles")
        set(ENV{VCPKG_DEFAULT_TRIPLET} "x64-mingw-static")
        set(ENV{VCPKG_DEFAULT_HOST_TRIPLET} "x64-mingw-static")
        set(VCPKG_TARGET_TRIPLET "x64-mingw-static" CACHE STRING "x64-mingw-static")
    endif()

endif()

if(NOT DEFINED(${CMAKE_TOOLCHAIN_FILE}))
set(CMAKE_TOOLCHAIN_FILE "${CMAKE_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake")
endif()

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_FLAGS "-O2" CACHE STRING "-O2")

set(PROJECT_NAME minecraft)
project(${PROJECT_NAME} LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20) 

set( LOCAL_PATH "${CMAKE_BINARY_DIR}/${CMAKE_SYSTEM_NAME}/${CMAKE_BUILD_TYPE}")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${LOCAL_PATH}/bin")
set( RESOURCES_DIR "${LOCAL_PATH}")
file(COPY "res" DESTINATION ${RESOURCES_DIR})

set(SOURCE "src/main.cpp")
add_executable(${PROJECT_NAME} 
    ${SOURCE}
    "src/Game.cpp"
    "src/Renderer.cpp"
    "src/Cube.cpp"
    "src/Shaders.cpp"
    "src/Texture.cpp"
    "src/Camera.cpp"
    "src/Time.cpp"
    "src/Player.cpp"
    "src/Cross.cpp"
    "src/Collider.cpp"
    )

find_package(SFML 2.6.1 COMPONENTS window REQUIRED)
target_link_libraries(${PROJECT_NAME} sfml-window)

find_package(OpenGL REQUIRED)
include_directories(${PROJECT_NAME} PRIVATE ${OPENGL_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES})


find_package(GLEW REQUIRED)
include_directories(${PROJECT_NAME} PRIVATE ${GLEW_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${GLEW_LIBRARIES})

find_package(glm CONFIG REQUIRED)
target_include_directories(${PROJECT_NAME} PRIVATE ${GLM})

find_package(Stb REQUIRED)
include_directories(${PROJECT_NAME} PRIVATE ${Stb_INCLUDE_DIR})
add_library(stb_image STATIC  "${CMAKE_SOURCE_DIR}/stb_image.cpp")
target_link_libraries(${PROJECT_NAME} stb_image)
