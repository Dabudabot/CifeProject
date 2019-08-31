#include <boost/test/unit_test.hpp>

#include "../src/cryptors/Cryptor.h"

BOOST_AUTO_TEST_CASE(simple_test1) {
  int a = 42;
  int b = 43;
  BOOST_CHECK_EQUAL(a, b);
}