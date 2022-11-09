project(test)
set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(CMAKE_CXX_STANDARD 17)

add_executable(example example.cc)
target_link_libraries(example PUBLIC pthread)