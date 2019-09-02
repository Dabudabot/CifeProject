#include <boost/test/unit_test.hpp>

#include "../src/cryptors/Cryptor.h"
#include "cryptors/huffman/Huffman.h"

BOOST_AUTO_TEST_CASE(EncryptHuffman) {

  auto cryptor = Cryptor::cryptor_factory(
    "-e",
    "Huffman",
    "Test message"
  );

  const auto in_msg = cryptor->get_in_message();

  BOOST_CHECK_EQUAL(in_msg, "Test message");

  cryptor->run();

  const auto out_msg = cryptor->get_out_message();

  BOOST_CHECK_EQUAL(out_msg, "00001000001000000000000101010100000000010110000100000001011001010000001101100111000000010110110100000001011100110000001101110100000000011101011000111000000110101110111101");
}

BOOST_AUTO_TEST_CASE(DecryptHuffman) {

  auto cryptor = Cryptor::cryptor_factory(
    "-d",
    "Huffman",
    "00001000001000000000000101010100000000010110000100000001011001010000001101100111000000010110110100000001011100110000001101110100000000011101011000111000000110101110111101"
  );

  const auto in_msg = cryptor->get_in_message();

  BOOST_CHECK_EQUAL(in_msg, "00001000001000000000000101010100000000010110000100000001011001010000001101100111000000010110110100000001011100110000001101110100000000011101011000111000000110101110111101");

  cryptor->run();

  const auto out_msg = cryptor->get_out_message();

  BOOST_CHECK_EQUAL(out_msg, "Test message");
}

BOOST_AUTO_TEST_CASE(CheckHuffmanNode) {
  const auto right = HuffmanNode('a', 42);

  BOOST_CHECK_EQUAL(right.get_c(), 'a');
  BOOST_CHECK_EQUAL(right.get_n(), 42);

  const auto left = HuffmanNode('b', 43);

  const auto node = HuffmanNode(
    std::make_shared<HuffmanNode>(left), 
    std::make_shared<HuffmanNode>(right)
  );

  BOOST_CHECK_EQUAL(node.get_left()->get_c(), 'b');
  BOOST_CHECK_EQUAL(node.get_left()->get_n(), 43);
  BOOST_CHECK_EQUAL(node.get_right()->get_c(), 'a');
  BOOST_CHECK_EQUAL(node.get_right()->get_n(), 42);
}

BOOST_AUTO_TEST_CASE(CheckHuffmanComparator) {
  const auto comparator = HuffmanComparator();

  const auto right = HuffmanNode('a', 42);
  const auto left = HuffmanNode('b', 43);

  const auto result_true = comparator.operator()(
    std::make_shared<HuffmanNode>(right),
    std::make_shared<HuffmanNode>(left));

  const auto result_false = comparator.operator()(
    std::make_shared<HuffmanNode>(left),
    std::make_shared<HuffmanNode>(right));

  BOOST_CHECK_EQUAL(result_true, true);
  BOOST_CHECK_EQUAL(result_false, false);
}