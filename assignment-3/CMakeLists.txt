cmake_minimum_required(VERSION 3.0)
project(assignment_3)

set(CMAKE_CXX_STANDARD 11)
add_compile_options(-Wall -Wextra -pedantic -Werror -fstack-protector -fstack-protector-all)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address")
set(CMAKE_LINKER_FLAGS_DEBUG "${CMAKE_LINKER_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address")


find_package(Threads)

add_executable(dining-philosophers dining-philosophers.cpp)
target_link_libraries(dining-philosophers ${CMAKE_THREAD_LIBS_INIT})

add_executable(sieve-of-eratosthenes sieve-of-eratosthenes.cpp)
target_link_libraries(sieve-of-eratosthenes ${CMAKE_THREAD_LIBS_INIT})

add_executable(bench benchmark_example.cpp)
target_link_libraries(bench ${CMAKE_THREAD_LIBS_INIT})
