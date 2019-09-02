//
// Created by dabudabot on 14.12.17.
//

#pragma once
#include "../Cryptor.h"
#include <list>
#include <map>
/*
 * Node to build Huffman tree
 */
class HuffmanNode {
  char c_;
  int n_;
  std::shared_ptr<HuffmanNode> left_, right_;
public:
  HuffmanNode(const char c, const int n) : c_(c), n_(n), left_(nullptr), right_(nullptr) {};
  HuffmanNode(const std::shared_ptr<HuffmanNode>& left,
              const std::shared_ptr<HuffmanNode>& right);

  [[nodiscard]] char get_c() const { return c_; }
  [[nodiscard]] int get_n() const { return n_; }
  [[nodiscard]] std::shared_ptr<HuffmanNode> get_left() const { return left_; }
  [[nodiscard]] std::shared_ptr<HuffmanNode> get_right() const { return right_; }
};

/*
 * To sort leaves we need to know how to compare them
 */
struct HuffmanComparator {
  bool operator()(const std::shared_ptr<HuffmanNode>& l,
    const std::shared_ptr<HuffmanNode>& r) const {
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
class HuffmanEncoder final : public Cryptor {

  std::list<std::shared_ptr<HuffmanNode>> nodes_;
  std::string temp_code_;
  std::map<char, std::string> table_;

  void build(const std::shared_ptr<HuffmanNode>& root);
public:
  explicit HuffmanEncoder(const std::string& message) : Cryptor(message) { set_show(true); };
  void run() override;
};

/*
 * Huffman decoding
 * encoded sequence should be represented as:
 * n = 1 byte long number - dictionary length
 * n times 1 byte long char and 1 byte long frequency
 * finally encoded message
 */
class HuffmanDecoder final : public Cryptor {

  std::list<std::shared_ptr<HuffmanNode>> nodes_;
public:
  explicit HuffmanDecoder(const std::string& message) : Cryptor(message) {};
  void run() override;
};
