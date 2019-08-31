find_package (Boost COMPONENTS unit_test_framework REQUIRED)
include_directories(${CifeProject_SOURCE_DIR}/src
    ${Boost_INCLUDE_DIRS}
    )

add_definitions(-DBOOST_TEST_DYN_LINK -DBOOST_TEST_MAIN)


SET(test_sources
    "Cryptor_test.cpp"
    "Deflate_test.cpp"
    "Huffman_test.cpp"
    "LZ77_test.cpp"
)

#for each source: build an executable, register it as a test
FOREACH(test_source ${test_sources})
    GET_FILENAME_COMPONENT(test_name ${test_source} NAME_WE)
    ADD_EXECUTABLE(${test_name} ${test_source})
    TARGET_LINK_LIBRARIES(${test_name}
			  CifeCryptors
			  ${Boost_LIBRARIES}
			  )

    ADD_TEST(NAME ${test_name} COMMAND ${test_name})
    SET_PROPERTY(TARGET ${test_name} PROPERTY CXX_STANDARD 17)

ENDFOREACH(test_source)