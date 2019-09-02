#include <boost/test/unit_test.hpp>

#include "../src/cryptors/Cryptor.h"
#include "cryptors/lz77/LZ77.h"

BOOST_AUTO_TEST_CASE(EncryptLz77) {

  auto cryptor = Cryptor::cryptor_factory(
    "-e",
    "Lz77",
    "Test message"
  );

  const auto in_msg = cryptor->get_in_message();

  BOOST_CHECK_EQUAL(in_msg, "Test message");

  cryptor->run();

  const auto out_msg = cryptor->get_out_message();

  BOOST_CHECK_EQUAL(out_msg, "1100011011011110111101101000000101");
}

BOOST_AUTO_TEST_CASE(DecryptLz77) {

  auto cryptor = Cryptor::cryptor_factory(
    "-d",
    "Lz77",
    "1100011011011110111101101000000101"
  );

  const auto in_msg = cryptor->get_in_message();

  BOOST_CHECK_EQUAL(in_msg, "1100011011011110111101101000000101");

  cryptor->run();

  const auto out_msg = cryptor->get_out_message();

  BOOST_CHECK_EQUAL(out_msg, "Test message");
}

BOOST_AUTO_TEST_CASE(CheckLz77Node) {
  const auto node = Lz77Node('a', 42, 21);

  BOOST_CHECK_EQUAL(node.get_symbol(), 'a');
  BOOST_CHECK_EQUAL(node.get_offset(), 42);
  BOOST_CHECK_EQUAL(node.get_amount(), 21);
}