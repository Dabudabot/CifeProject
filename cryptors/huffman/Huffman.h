//
// Created by dabudabot on 14.12.17.
//

#ifndef CIFEPROJECT_HUFFMAN_H
#define CIFEPROJECT_HUFFMAN_H


#include "../Cryptor.h"

/*
 * Node to build Huffman tree
 */
class HuffmanNode {
private:
    char c;
    int n;
    shared_ptr<HuffmanNode> left, right;
public:
    HuffmanNode(char c, int n) : c(c), n(n), left(nullptr), right(nullptr) {};
    HuffmanNode(shared_ptr<HuffmanNode> left,
                 shared_ptr<HuffmanNode> right);

    char get_c() {return c;}
    int get_n() {return n;}
    shared_ptr<HuffmanNode> get_left() {return left;}
    shared_ptr<HuffmanNode> get_right() {return right;}
};

/*
 * To sort leaves we need to know how to compare them
 */
struct HuffmanComparator {
    bool operator()(const shared_ptr<HuffmanNode> &l,
                    const shared_ptr<HuffmanNode> &r) const {
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
    list<shared_ptr<HuffmanNode>> nodes;
    string temp_code;
    map<char, string> table;

    void build(const shared_ptr<HuffmanNode> &root);
public:
    explicit HuffmanEncoder(const string &message) : Cryptor(message) {set_show(true);};
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
    list<shared_ptr<HuffmanNode>> nodes;
public:
    explicit HuffmanDecoder(const string &message) : Cryptor(message) {};
    void run() override;
};


#endif //CIFEPROJECT_HUFFMAN_H
