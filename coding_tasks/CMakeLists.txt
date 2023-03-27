cmake_minimum_required(VERSION 3.22)

project(
  Playground
  VERSION 1.0
  LANGUAGES CXX
)

add_subdirectory(warmup/)
add_subdirectory(graph/)
add_subdirectory(bits_op/)

# leet code tasks
add_subdirectory(sliding_window/)
add_subdirectory(fast_and_slow_ptr/)
add_subdirectory(cyclic_sort/)
add_subdirectory(two_heaps/)
add_subdirectory(substring/)
add_subdirectory(linked_list/)
add_subdirectory(threads/)

# hackerrank
add_subdirectory(hackerrank/)
