cmake_minimum_required(VERSION 3.9)
project(CifeProject)

set(CMAKE_CXX_STANDARD 11)

add_executable(CifeProject main.cpp utils/helper.h cryptors/Cryptor.h cryptors/huffman/Huffman.cpp cryptors/huffman/Huffman.h cryptors/deflate/Deflate.cpp cryptors/deflate/Deflate.h cryptors/lz77/LZ77.cpp cryptors/lz77/LZ77.h cryptors/Cryptor.cpp)