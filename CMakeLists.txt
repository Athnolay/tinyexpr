cmake_minimum_required(VERSION 3.10)
Project(opencv_pratice)
file(GLOB_RECURSE SRC "./partice/*.cpp" "./partice/*.c")
include_directories("./partice")
# add_executable(exec_cv_test main.cpp ${SRC})
# target_link_libraries(exec_cv_test pthread)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})


add_executable(test main.cpp ${SRC})
target_link_libraries(test ${OpenCV_LIBS})

# add_executable(quick_start quick_start.cpp)
# target_link_libraries(quick_start ${OpenCV_LIBS})