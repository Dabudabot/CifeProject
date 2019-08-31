//
// Created by dabudabot on 15.12.17.
//

#include "Cryptor.h"
#include "deflate/Deflate.h"
#include "lz77/LZ77.h"
#include "huffman/Huffman.h"

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
        for (char i : get_in_message()) {
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
        for (char i : get_out_message()) {
            ss2 << bitset<8>(static_cast<unsigned long long int>(i)) << flush;
        }
        s2 = ss2.str();
        cout << " " << s2 << endl;
    } else {
        s2 = get_out_message();
    }
    cout << "---------------" << endl;

    if (show) {
        auto diff = s.size() - s2.size();
        auto compression = (diff * 100.0) / s.size();
        cout << "compression: " << compression << "%" << endl;
        cout << "---------------" << endl;
    }
}

std::unique_ptr<Cryptor> Cryptor::cryptor_factory(const string& mode, const string& type, const string& message)
{
  if (mode == ENCRYPT_KEY &&
    type == HUFFMAN_KEY) {
    return unique_ptr<Cryptor>(new HuffmanEncoder(message));
  }
  else if (mode == DECRYPT_KEY &&
    type == HUFFMAN_KEY) {
    return unique_ptr<Cryptor>(new HuffmanDecoder(message));

  }
  else if (mode == ENCRYPT_KEY &&
    type == LZ77_KEY) {
    return unique_ptr<Cryptor>(new LZ77Encoder(message));
  }
  else if (mode == DECRYPT_KEY &&
    type == LZ77_KEY) {
    return unique_ptr<Cryptor>(new LZ77Decoder(message));

  }
  else if (mode == ENCRYPT_KEY &&
    type == DEFLATE_KEY) {
    return unique_ptr<Cryptor>(new DeflateEncoder(message));
  }
  else if (mode == DECRYPT_KEY &&
    type == DEFLATE_KEY) {
    return unique_ptr<Cryptor>(new DeflateDecoder(message));
  }
  else {
    throw exception();
  }
}
