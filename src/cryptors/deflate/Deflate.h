//
// Created by dabudabot on 15.12.17.
//

#pragma once

#include "../Cryptor.h"
#include "../lz77/LZ77.h"
#include "../huffman/Huffman.h"

class DeflateEncoder : public Cryptor {
private:

public:
    explicit DeflateEncoder(const std::string &message) : Cryptor(message) {set_show(true);};
    void run() override;
};

class DeflateDecoder : public Cryptor {
private:

public:
    explicit DeflateDecoder(const std::string &message) : Cryptor(message) {};
    void run() override;
};
