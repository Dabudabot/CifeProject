#include "../src/main.h"
#include "..//src/utils/helper.h"

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
  boost::test_tools::output_test_stream output;
  boost::test_tools::output_test_stream check;

  {
    cout_redirect guard(output.rdbuf());

    BOOST_CHECK_EQUAL(main(1, "CifeProject"), 1);
  }

  {
    cout_redirect guard(check.rdbuf());

    helper::show_usage();
  }

  BOOST_CHECK(output.output_test_stream("Test\n"));
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