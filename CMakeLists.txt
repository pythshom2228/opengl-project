cmake_minimum_required(VERSION 3.29)


set(PROJECT_NAME app)
project(${PROJECT_NAME} LANGUAGES CXX)


set(CMAKE_CXX_STANDARD 20) 

if ( NOT DEFINED CMAKE_BUILD_TYPE )
  set( CMAKE_BUILD_TYPE  "Debug" CACHE STRING "Build type" )
endif ()

file(MAKE_DIRECTORY ${CMAKE_BUILD_TYPE})

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BUILD_TYPE}/bin")


set(SOURCE "src/main.cpp")

add_executable(${PROJECT_NAME} ${SOURCE})

#add_library(stb_image STATIC  "src/stb_image.cpp")

file(COPY "res" DESTINATION "${CMAKE_BINARY_DIR}/..")

find_package(SFML 2.6.1 COMPONENTS window REQUIRED)
target_link_libraries(${PROJECT_NAME} sfml-window)

find_package(OpenGL REQUIRED)
target_include_directories(${PROJECT_NAME} PRIVATE ${OPENGL_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES})


find_package(GLEW REQUIRED)
target_include_directories(${PROJECT_NAME} PRIVATE ${GLEW_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${GLEW_LIBRARIES})

find_package(glm CONFIG REQUIRED)
target_include_directories(${PROJECT_NAME} PRIVATE ${GLM})
#target_link_libraries(${PROJECT_NAME} glm::glm)

find_package(Stb REQUIRED)
target_include_directories(${PROJECT_NAME} PRIVATE ${Stb_INCLUDE_DIR})
