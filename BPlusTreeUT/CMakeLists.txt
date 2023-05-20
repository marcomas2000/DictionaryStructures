cmake_minimum_required (VERSION 3.10.2)
project(BPlusTreeTestProj)

enable_testing()
find_package(GTest REQUIRED)

add_executable(BPlusTreeTest BPlusTreeTest.cpp)
target_include_directories(BPlusTreeTest  PRIVATE "..")
target_link_libraries(BPlusTreeTest PRIVATE GTest::GTest GTest::Main BPlusTree)
add_test(BPlusTreeTestProj BPlusTreeTest)
