#include "../src/main.h"
#include "../src/utils/helper.h"

#define BOOST_TEST_MODULE VsidCommonTest
#include <boost/test/unit_test.hpp>
#include <boost/test/output_test_stream.hpp>
#include <iostream>

BOOST_AUTO_TEST_SUITE(main_tests)

struct cout_redirect {
  cout_redirect(std::streambuf* new_buffer)
    : old(std::cout.rdbuf(new_buffer))
  { }

  ~cout_redirect() {
    std::cout.rdbuf(old);
  }

private:
  std::streambuf* old;
};

BOOST_AUTO_TEST_CASE(no_input)
{
  char* argv[] = { "CifeProject" };
  int result = main(1, argv);

  BOOST_CHECK_EQUAL(result, 10);

  boost::test_tools::output_test_stream output;
  {
    cout_redirect guard(output.rdbuf());

    helper::show_usage();
  }


  std::string right_output = "usage: \n  <CifeProject> -e Huffman \"text_to_encrypt\"\n  <CifeProject> -d Huffman \"text_to_decrypt\"\n\
      <CifeProject> -e lzw \"text_to_encrypt\"\n  <CifeProject> -d lzw \"text_to_decrypt\"\n\
      <CifeProject> -e LZ77 \"text_to_encrypt\"\n  <CifeProject> -d LZ77 \"text_to_decrypt\"\n\
      <CifeProject> -e Deflate \"text_to_encrypt\"\n  <CifeProject> -d Deflate \"text_to_decrypt\"\n";

  BOOST_CHECK(output.is_equal(right_output));
}

BOOST_AUTO_TEST_CASE(wrong_input)
{

}

BOOST_AUTO_TEST_CASE(huffman_e)
{

}

BOOST_AUTO_TEST_CASE(huffman_d)
{

}

BOOST_AUTO_TEST_CASE(deflate_e)
{

}

BOOST_AUTO_TEST_CASE(deflate_d)
{

}

BOOST_AUTO_TEST_CASE(lz77_e)
{

}

BOOST_AUTO_TEST_CASE(lz77_d)
{

}

BOOST_AUTO_TEST_SUITE_END()
