cmake_minimum_required(VERSION 3.9)
project(CifeTest)

# find a boost install with the libraries unit_test_framework
find_package(Boost 1.46.1 REQUIRED COMPONENTS unit_test_framework)

# Add an library for the example classes
add_library(cife_boost_unit_test
    "../src/main.cpp" 
    "../src/utils/helper.h" 
    "../src/cryptors/Cryptor.h" 
    "../src/cryptors/huffman/Huffman.cpp" 
    "../src/cryptors/huffman/Huffman.h" 
    "../src/cryptors/deflate/Deflate.cpp" 
    "../src/cryptors/deflate/Deflate.h" 
    "../src/cryptors/lz77/LZ77.cpp" 
    "../src/cryptors/lz77/LZ77.h" 
    "../src/cryptors/Cryptor.cpp"
)

target_include_directories(cife_boost_unit_test
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(cife_boost_unit_test
    PUBLIC
        Boost::boost
)

# enable CTest testing
enable_testing()

# Add a testing executable
add_executable(cife_tests 
  "cryptors/Cryptor_test.cpp"
  "cryptors/Deflate_test.cpp"
  "cryptors/Huffman_test.cpp"
  "cryptors/LZ77_test.cpp"
)

add_executable(cife_main_tests 
  "main_test.cpp"
)

add_executable(cife_helper_tests 
  "utils/helper_test.cpp" 
)

target_link_libraries(cife_tests
    cife_boost_unit_test
    Boost::unit_test_framework
)

target_link_libraries(cife_main_tests
    cife_boost_unit_test
    Boost::unit_test_framework
)

target_link_libraries(cife_helper_tests
    cife_boost_unit_test
    Boost::unit_test_framework
)

target_compile_definitions(cife_tests
    PRIVATE
        BOOST_TEST_DYN_LINK
)

target_compile_definitions(cife_main_tests
    PRIVATE
        BOOST_TEST_DYN_LINK
)

target_compile_definitions(cife_helper_tests
    PRIVATE
        BOOST_TEST_DYN_LINK
)

add_test(test_all cife_tests cife_main_tests cife_helper_tests)