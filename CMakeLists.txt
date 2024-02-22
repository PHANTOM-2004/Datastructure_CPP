cmake_minimum_required(VERSION 3.2.0)

project("MyDSA_Implementation")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(${CMAKE_CXX_COMPILER_ID} STREQUAL MSVC)
    add_compile_options(/utf-8)
    message("compiler MSVC")
endif()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include_directories(./common)
include_directories(./src)

add_subdirectory(./src/Vector)
add_subdirectory(./src/PQ_CompleteHeap)
add_subdirectory(./src/List)
add_subdirectory(./src/Stack)
add_subdirectory(./src/Queue)
add_subdirectory(./src/Steap)
add_subdirectory(./src/Queap)
add_subdirectory(./src/Bitmap)
add_subdirectory(./src/BinTree)
add_subdirectory(./src/BST)
add_subdirectory(./src/AVL)
add_subdirectory(./src/Splay)
add_subdirectory(./src/Hashtable)
add_subdirectory(./src/Skiplist)
add_subdirectory(./src/RBTree)