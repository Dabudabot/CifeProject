//
// Created by dabudabot on 14.12.17.
//

#pragma once
#include "../Cryptor.h"

/*
 * Node to build Huffman tree
 */
class HuffmanNode {
private:
    char c;
    int n;
    std::shared_ptr<HuffmanNode> left, right;
public:
    HuffmanNode(char c, int n) : c(c), n(n), left(nullptr), right(nullptr) {};
    HuffmanNode(std::shared_ptr<HuffmanNode> left,
      std::shared_ptr<HuffmanNode> right);

    char get_c() {return c;}
    int get_n() {return n;}
    std::shared_ptr<HuffmanNode> get_left() {return left;}
    std::shared_ptr<HuffmanNode> get_right() {return right;}
};

/*
 * To sort leaves we need to know how to compare them
 */
struct HuffmanComparator {
    bool operator()(const std::shared_ptr<HuffmanNode> &l,
                    const std::shared_ptr<HuffmanNode> &r) const {
        return l->get_n() < r->get_n();
    }
};

/*
 * Huffman encoding
 * encoded sequence is represented as:
 * n = 1 byte long number - dictionary length
 * n times 1 byte long char and 1 byte long frequency
 * finally encoded message
 */
class HuffmanEncoder : public Cryptor {
private:
    std::list<std::shared_ptr<HuffmanNode>> nodes;
    std::string temp_code;
    std::map<char, std::string> table;

    void build(const std::shared_ptr<HuffmanNode> &root);
public:
    explicit HuffmanEncoder(const std::string &message) : Cryptor(message) {set_show(true);};
    void run() override;
};

/*
 * Huffman decoding
 * encoded sequence should be represented as:
 * n = 1 byte long number - dictionary length
 * n times 1 byte long char and 1 byte long frequency
 * finally encoded message
 */
class HuffmanDecoder : public Cryptor {
private:
    std::list<std::shared_ptr<HuffmanNode>> nodes;
public:
    explicit HuffmanDecoder(const std::string &message) : Cryptor(message) {};
    void run() override;
};
