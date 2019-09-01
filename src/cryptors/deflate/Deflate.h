//
// Created by dabudabot on 15.12.17.
//

#pragma once

#include "../Cryptor.h"

class DeflateEncoder : public Cryptor {

public:
  explicit DeflateEncoder(const std::string& message) : Cryptor(message) { set_show(true); };
  void run() override;
};

class DeflateDecoder : public Cryptor {

public:
  explicit DeflateDecoder(const std::string& message) : Cryptor(message) {};
  void run() override;
};
