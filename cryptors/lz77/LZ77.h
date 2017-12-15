//
// Created by dabudabot on 15.12.17.
//

#ifndef CIFEPROJECT_LZ77_H
#define CIFEPROJECT_LZ77_H

#include "../Cryptor.h"

class LZ77Node {
private:
    int offset;
    int amount;
    char symbol;
public:
    explicit LZ77Node(char c,
                      int offset,
                      int amount) :
            symbol(c),
            offset(offset),
            amount(amount) {}
    char get_symbol() {return symbol;}
    int get_offset() {return offset;}
    int get_amount() {return amount;}
};

class LZ77Encoder : public Cryptor {
private:

public:
    explicit LZ77Encoder(const string &message) : Cryptor(message) {set_show(true);};
    void run() override;
};

class LZ77Decoder : public Cryptor {
private:

public:
    explicit LZ77Decoder(const string &message) : Cryptor(message) {};
    void run() override;
};

#endif //CIFEPROJECT_LZ77_H
