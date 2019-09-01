add_library(CifeCryptors "cryptors/Cryptor.h" 
"cryptors/huffman/Huffman.cpp" 
"cryptors/huffman/Huffman.h" 
"cryptors/deflate/Deflate.cpp" 
"cryptors/deflate/Deflate.h" 
"cryptors/lz77/LZ77.cpp" 
"cryptors/lz77/LZ77.h" 
"cryptors/Cryptor.cpp")
add_executable(CifeDemo "main.cpp" )
target_link_libraries(CifeDemo CifeCryptors)

set_property(TARGET CifeDemo PROPERTY CXX_STANDARD 17)
set_property(TARGET CifeCryptors PROPERTY CXX_STANDARD 17)

target_compile_options(CifeCryptors PUBLIC -Wall -pedantic)