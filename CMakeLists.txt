# configure CMAKE
cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# custom variables

# set include directory
include_directories(include)

# create teh project : Ray tracer
project("Ray Tracer" VERSION 0.1)
add_executable(ray-tracer apps/main.cpp)
message("Project : " ${PROJECT_NAME} " v" ${PROJECT_VERSION})
message("Building folder : " ${PROJECT_BINARY_DIR})

# add libraries
# TODO : decompose in lib (maths, ...)
file(GLOB_RECURSE SRC src/*.cpp)
add_library(src SHARED ${SRC})
target_link_libraries(ray-tracer src)

# installation
install(TARGETS ray-tracer DESTINATION bin)

