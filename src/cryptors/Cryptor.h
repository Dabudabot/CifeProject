//
// Created by dabudabot on 14.12.17.
//
// Abstract encrypt

#pragma once

#include <bitset>
#include <memory>

/*
* All constant keys kept here
*/
constexpr char ENCRYPT_KEY[] = "-e";
constexpr char DECRYPT_KEY[] = "-d";
constexpr char HUFFMAN_KEY[] = "Huffman";
constexpr char LZW_KEY[] = "lzw";
constexpr char LZ77_KEY[] = "LZ77";
constexpr char DEFLATE_KEY[] = "Deflate";

class Cryptor {

  std::string in_message_;
  std::string out_message_;
  bool show_ = false;
public:
  virtual ~Cryptor() = default;

  Cryptor(Cryptor&) = delete;
  Cryptor(Cryptor&&) = delete;
  Cryptor& operator= (const Cryptor&) = delete;
  Cryptor& operator= (Cryptor&&) = delete;

  explicit Cryptor(std::string message) : in_message_(std::move(message)) {};
  virtual void run() = 0;
  virtual void show_statistics();
  void set_out_message(std::string message) { this->out_message_ = std::move(message); }
  [[nodiscard]] std::string get_in_message() const { return in_message_; }
  [[nodiscard]] std::string get_out_message() const { return out_message_; }
  void set_show(const bool show) { this->show_ = show; }

  /*
  * Factory method to get correct cryption algorithm depending on mode and type
  */
  static std::unique_ptr<Cryptor> cryptor_factory(
    const std::string& mode,
    const std::string& type,
    const std::string& message
  );

};
