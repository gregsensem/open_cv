cmake_minimum_required(VERSION "3.5")

# name of this example project
project(transform_matrix)

# set OpenCV_DIR variable equal to the path to the cmake
# files within the previously installed opencv program
set(OpenCV_DIR )

# Tell compiler to use C++ 14 features 
set(CMAKE_CXX_STANDARD 14)

set(CMAKE_BUILD_TYPE Debug)

# configure the necessary common CMake environment variables
# needed to include and link the OpenCV program into this
# demo project, namely OpenCV_INCLUDE_DIRS and OpenCV_LIBS
find_package( OpenCV REQUIRED )

# tell the build to include the headers from OpenCV
include_directories( ${OpenCV_INCLUDE_DIRS} )

# specify the executable target to be built
add_executable(transform_matrix_2d transform_matrix_2d.cpp)

# tell it to link the executable target against OpenCV
target_link_libraries(transform_matrix_2d ${OpenCV_LIBS} )
