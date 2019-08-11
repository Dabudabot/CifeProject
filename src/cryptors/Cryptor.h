//
// Created by dabudabot on 14.12.17.
//
// Abstract encryptor

#pragma once

#include <iostream>
#include <bitset>
#include <sstream>
#include <memory>
#include <map>
#include <list>
#include <vector>

class Cryptor {
private:
    std::string in_message;
    std::string out_message;
    bool show = false;
public:
    explicit Cryptor(std::string message) : in_message(std::move(message)) {};
    virtual void run()=0;
    virtual void show_statistics();
    void set_out_message(std::string message) {this->out_message = std::move(message);}
    std::string get_in_message() {return in_message;}
    std::string get_out_message() {return out_message;}
    void set_show(bool show) {this->show = show;}
};
