cmake_minimum_required (VERSION 3.10.2)

set(BASE_SOURCES bplustree.cpp IdxFile.cpp Node.cpp)

add_library(BPlusTree STATIC ${BASE_SOURCES})
