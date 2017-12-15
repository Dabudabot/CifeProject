//
// Created by dabudabot on 15.12.17.
//

#ifndef CIFEPROJECT_DEFLATE_H
#define CIFEPROJECT_DEFLATE_H

#include "../Cryptor.h"
#include "../lz77/LZ77.h"
#include "../huffman/Huffman.h"

class DeflateEncoder : public Cryptor {
private:

public:
    explicit DeflateEncoder(const string &message) : Cryptor(message) {set_show(true);};
    void run() override;
};

class DeflateDecoder : public Cryptor {
private:

public:
    explicit DeflateDecoder(const string &message) : Cryptor(message) {};
    void run() override;
};


#endif //CIFEPROJECT_DEFLATE_H
