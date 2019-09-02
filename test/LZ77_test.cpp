#include <boost/test/unit_test.hpp>

#include "../src/cryptors/Cryptor.h"
#include "cryptors/lz77/LZ77.h"

BOOST_AUTO_TEST_CASE(EncryptLz77) {

  auto cryptor = Cryptor::cryptor_factory(
    "-e",
    "Lz77",
    "AAAAABBAAACCCCAAAAAAACCCCBBBBBBBDDAAAABBBBB"
  );

  const auto in_msg = cryptor->get_in_message();

  BOOST_CHECK_EQUAL(in_msg, "AAAAABBAAACCCCAAAAAAACCCCBBBBBBBDDAAAABBBBB");

  cryptor->run();

  const auto out_msg = cryptor->get_out_message();

  BOOST_CHECK_EQUAL(out_msg, "AAAAABBAAACCCC[13,4]A[11,6]BBBBBBBDD[33,6]BBB");
}

BOOST_AUTO_TEST_CASE(DecryptLz77) {

  auto cryptor = Cryptor::cryptor_factory(
    "-d",
    "Lz77",
    "AAAAABBAAACCCC[13,4]A[11,6]BBBBBBBDD[33,6]BBB"
  );

  const auto in_msg = cryptor->get_in_message();

  BOOST_CHECK_EQUAL(in_msg, "AAAAABBAAACCCC[13,4]A[11,6]BBBBBBBDD[33,6]BBB");

  cryptor->run();

  const auto out_msg = cryptor->get_out_message();

  BOOST_CHECK_EQUAL(out_msg, "AAAAABBAAACCCCAAAAAAACCCCBBBBBBBDDAAAABBBBB");
}

BOOST_AUTO_TEST_CASE(CheckLz77Node) {
  const auto node = Lz77Node('a', 42, 21);

  BOOST_CHECK_EQUAL(node.get_symbol(), 'a');
  BOOST_CHECK_EQUAL(node.get_offset(), 42);
  BOOST_CHECK_EQUAL(node.get_amount(), 21);
}