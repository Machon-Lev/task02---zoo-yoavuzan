# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.15)

project (ex02_Project02)

set (CMAKE_CXX_STANDARD 20)
set (CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_CXX_EXTENSIONS OFF)
if (MSVC)
	add_compile_options (/W4 /permissive- /Zc:externConstexpr /Zc:inline)
endif ()
# Include sub-projects.
add_executable (ex02_Project02 "include/Animal.h" "include/Lion.h" "include/Monkey.h" 
"include/direction.h" "include/Owl.h" "include/Zoo.h"
"src/Animal.cpp" "src/Lion.cpp" "src/Monkey.cpp" 
"src/Zoo.cpp" "src/Owl.cpp" "src/Location.cpp" 
"src/ex02_Project02.cpp"  )
add_subdirectory (include)
add_subdirectory (src)
