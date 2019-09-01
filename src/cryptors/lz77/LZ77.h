//
// Created by dabudabot on 15.12.17.
//

#pragma once

#include "../Cryptor.h"

class Lz77Node {

    char symbol_;
    int offset_;
    int amount_;

public:
    explicit Lz77Node(const char c,
                      const int offset,
                      const int amount) :
            symbol_(c),
            offset_(offset),
            amount_(amount) {}

    [[nodiscard]] char get_symbol() const {return symbol_;}
    [[nodiscard]] int get_offset() const {return offset_;}
    [[nodiscard]] int get_amount() const {return amount_;}
};

class Lz77Encoder final : public Cryptor {
public:
    explicit Lz77Encoder(const std::string &message) : Cryptor(message) {set_show(true);};
    void run() override;
};

class Lz77Decoder final : public Cryptor {
public:
    explicit Lz77Decoder(const std::string &message) : Cryptor(message) {};
    void run() override;
};
