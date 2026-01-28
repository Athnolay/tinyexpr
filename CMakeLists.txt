cmake_minimum_required(VERSION 3.10)
Project(tinyexpr)
file(GLOB_RECURSE SRC "./lib_code/*.cpp" "./lib_code/*.c")
include_directories("./lib_code")


add_executable(test main.cpp ${SRC})
# target_link_libraries(test ${OpenCV_LIBS})