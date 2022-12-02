cmake_minimum_required(VERSION 3.23)
project(thefinal)

set(CMAKE_CXX_STANDARD 14)
link_libraries(libwinmm.a)
link_libraries(libeasyx.a)
add_executable(thefinal main.cpp checkboard.cpp checkboard.h win_checker.cpp win_checker.h easyxfunctions.cpp easyxfunctions.h pages.cpp pages.h xytranslator.cpp xytranslator.h filedealer.cpp filedealer.h)

add_executable(win_checker win_checker.cpp)
add_executable(main main.cpp)