//
// Created by dabudabot on 15.12.17.
//

#include "Deflate.h"
using namespace std;

void DeflateEncoder::run() {
    cout << "Deflate encryption..." << endl;

    LZ77Encoder lz77(get_in_message());
    lz77.run();
    HuffmanEncoder huffman(lz77.get_out_message());
    huffman.run();
    set_out_message(huffman.get_out_message());

    cout << "encryption done" << endl;
}

void DeflateDecoder::run() {
    cout << "Deflate decryption..." << endl;

    HuffmanDecoder huffman(get_in_message());
    huffman.run();
    LZ77Decoder lz77(huffman.get_out_message());
    lz77.run();
    set_out_message(lz77.get_out_message());

    cout << "decryption done" << endl;
}
