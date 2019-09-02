#include <boost/test/unit_test.hpp>

#include "../src/cryptors/Cryptor.h"

BOOST_AUTO_TEST_CASE(SetShow) {

  auto cryptor = Cryptor::cryptor_factory(
    "-e",
    "Huffman",
    "Test message"
  );

  const auto before_show = cryptor->get_show();

  BOOST_CHECK_EQUAL(before_show, true);

  cryptor->set_show(false);

  const auto after_show = cryptor->get_show();

  BOOST_CHECK_EQUAL(after_show, false);
}

BOOST_AUTO_TEST_CASE(SetOut) {

  auto cryptor = Cryptor::cryptor_factory(
    "-e",
    "Huffman",
    "Test message"
  );

  cryptor->set_out_message("Test out message");

  BOOST_CHECK_EQUAL(cryptor->get_out_message(), "Test out message");
}

BOOST_AUTO_TEST_CASE(WrongMode) {

  BOOST_CHECK_THROW(Cryptor::cryptor_factory(
    "WRONG",
    "Huffman",
    "Test message"
  ), std::runtime_error);
}

BOOST_AUTO_TEST_CASE(WrongType) {

  BOOST_CHECK_THROW(Cryptor::cryptor_factory(
    "-e",
    "WRONG",
    "Test message"
  ), std::runtime_error);
}