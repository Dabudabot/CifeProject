//
// Created by dabudabot on 14.12.17.
//
// Huffman encoding algorithm

#include "Huffman.h"

HuffmanNode::HuffmanNode(shared_ptr<HuffmanNode> left,
                           shared_ptr<HuffmanNode> right) : c('0') {
    this->n = left->get_n() + right->get_n();
    this->left = left;
    this->right = right;
}

void HuffmanEncoder::run() {
    cout << "Huffman encryption..." << endl;

    //find number of occurrence of each symbol
    map<char, int> symbols;
    for (char &c : get_in_message()) {
        symbols[c]++;
    }

    //initial list of leaves & saving to output
    stringstream output;
    output << bitset<8>(symbols.size()) << flush;
    for (auto &symbol : symbols) {
        output << bitset<8>((unsigned long long int) symbol.first)
               << bitset<8>(static_cast<unsigned long long int>(symbol.second)) << flush;
        shared_ptr<HuffmanNode> node(new HuffmanNode(symbol.first, symbol.second));
        nodes.push_back(node);
    }

    //building the tree
    while (nodes.size() > 1) {
        nodes.sort(HuffmanComparator());

        auto left_son = nodes.front();
        nodes.pop_front();
        auto right_son = nodes.front();
        nodes.pop_front();

        shared_ptr<HuffmanNode> parent(new HuffmanNode(left_son, right_son));
        nodes.push_back(parent);
    }

    //building code table
    build(nodes.front());

    //saving encoded message
    for (char &c : get_in_message()) {
        output << table[c] << flush;
    }
    set_out_message(output.str());

    cout << "encryption done!" << endl;
}

void HuffmanEncoder::build(const shared_ptr<HuffmanNode> &root) {
    if (root->get_left() != nullptr) {
        temp_code.append("0");
        build(root->get_left());
    }

    if (root->get_right() != nullptr) {
        temp_code.append("1");
        build(root->get_right());
    }

    if (root->get_right() == nullptr &&
            root->get_left() == nullptr) {
        table[root->get_c()] = temp_code;
    }

    temp_code = temp_code.substr(0, temp_code.size() - 1);
}

void HuffmanDecoder::run() {
    cout << "Huffman decryption..." << endl;

    string s_amount = get_in_message().substr(0, 8);
    int amount = stoi(s_amount, nullptr, 2);
    map<char, int> symbols;
    for (int i = 0; i < amount*2; i += 2) {
        int char_index = 8 * (i + 1);
        int freq_index = 8 * (i + 2);
        string s_char = get_in_message().substr(static_cast<unsigned long>(char_index), 8);
        string s_freq = get_in_message().substr(static_cast<unsigned long>(freq_index), 8);
        symbols[stoi(s_char, nullptr, 2)] = stoi(s_freq, nullptr, 2);
    }

    for (auto &symbol : symbols) {
        shared_ptr<HuffmanNode> node(new HuffmanNode(symbol.first, symbol.second));
        nodes.push_back(node);
    }

    //building the tree
    while (nodes.size() > 1) {
        nodes.sort(HuffmanComparator());

        auto left_son = nodes.front();
        nodes.pop_front();
        auto right_son = nodes.front();
        nodes.pop_front();

        shared_ptr<HuffmanNode> parent(new HuffmanNode(left_son, right_son));
        nodes.push_back(parent);
    }

    auto root = nodes.front();

    stringstream output;
    //saving decoded message
    for (char &c : get_in_message().substr(static_cast<unsigned long>((amount * 16) + 8))) {
        if (c == '0') {
            root = root->get_left();
        } else if (c == '1') {
            root = root->get_right();
        }

        if (root->get_right() == nullptr &&
                root->get_left() == nullptr) {
            output << root->get_c() << flush;
            root = nodes.front();
        }
    }
    set_out_message(output.str());

    cout << "decryption done!" << endl;
}
