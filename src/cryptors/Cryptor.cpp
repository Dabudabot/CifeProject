//
// Created by dabudabot on 15.12.17.
//

#include "Cryptor.h"
#include "deflate/Deflate.h"
#include "lz77/LZ77.h"
#include "huffman/Huffman.h"

#include <iostream>
#include <sstream>
#include <bitset>

using namespace std;

void Cryptor::show_statistics() {
  string s;
  string s2;
  cout << "---------------" << endl;
  cout << "input message: " << endl;
  cout << " " << get_in_message() << endl;
  if (get_in_message().find_first_not_of("01") != string::npos) {
    cout << "or binary: " << endl;
    stringstream ss;
    for (auto i : get_in_message()) {
      ss << bitset<8>(static_cast<unsigned long long int>(i)) << flush;
    }
    s = ss.str();
    cout << " " << s << endl;
  }
  cout << endl;

  cout << "output: " << endl;
  cout << " " << get_out_message() << endl;
  if (get_out_message().find_first_not_of("01") != string::npos) {
    cout << "or binary: " << endl;
    stringstream ss2;
    for (auto i : get_out_message()) {
      ss2 << bitset<8>(static_cast<unsigned long long int>(i)) << flush;
    }
    s2 = ss2.str();
    cout << " " << s2 << endl;
  }
  else {
    s2 = get_out_message();
  }
  cout << "---------------" << endl;

  if (show_) {
    const auto diff = s.size() - s2.size();
    const auto compression = (diff * 100.0) / s.size();
    cout << "compression: " << compression << "%" << endl;
    cout << "---------------" << endl;
  }
}

std::unique_ptr<Cryptor> Cryptor::cryptor_factory(
  const bool mode,
  const Cryptors type,
  const std::string& message
) {
  if (mode &&
    type == Cryptors::Huffman) {
    return std::unique_ptr<Cryptor>(std::make_unique<HuffmanEncoder>(message));
  }
  if (!mode &&
    type == Cryptors::Huffman) {
    return std::unique_ptr<Cryptor>(std::make_unique<HuffmanDecoder>(message));
  }
  if (mode &&
    type == Cryptors::Lz77) {
    return std::unique_ptr<Cryptor>(std::make_unique<Lz77Encoder>(message));
  }
  if (!mode &&
    type == Cryptors::Lz77) {
    return std::unique_ptr<Cryptor>(std::make_unique<Lz77Decoder>(message));

  }
  if (mode &&
    type == Cryptors::Deflate) {
    return std::unique_ptr<Cryptor>(std::make_unique<DeflateEncoder>(message));
  }
  if (!mode &&
    type == Cryptors::Deflate) {
    return std::unique_ptr<Cryptor>(std::make_unique<DeflateDecoder>(message));
  }

  throw runtime_error("Not implemented factory case");
}

std::unique_ptr<Cryptor> Cryptor::cryptor_factory(
  const std::string& mode,
  const std::string& type,
  const std::string& message)
{
  bool b_mode;
  Cryptors c_type;

  if (mode == ENCRYPT_KEY) {
    b_mode = true;
  }
  else if (mode == DECRYPT_KEY) {
    b_mode = false;
  }
  else {
    const auto msg = "Not possible mode: " + mode;
    throw runtime_error(msg.c_str());
  }

  if (type == HUFFMAN_KEY) {
    c_type = Cryptors::Huffman;
  }
  else if (type == LZ77_KEY) {
    c_type = Cryptors::Lz77;
  }
  else if (type == DEFLATE_KEY) {
    c_type = Cryptors::Deflate;
  }
  else {
    const auto msg = "Not possible type: " + type;
    throw runtime_error(msg.c_str());
  }

  return cryptor_factory(b_mode, c_type, message);
}