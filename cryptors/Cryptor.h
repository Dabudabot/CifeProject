//
// Created by dabudabot on 14.12.17.
//
// Abstract encryptor

#ifndef CIFEPROJECT_CRYPTOR_H
#define CIFEPROJECT_CRYPTOR_H

#include <iostream>
#include <bitset>
#include <sstream>
#include <memory>
#include <map>
#include <list>
#include <vector>

using namespace std;

class Cryptor {
private:
    string in_message;
    string out_message;
    bool show = false;
public:
    explicit Cryptor(string message) : in_message(move(message)) {};
    virtual void run()=0;
    virtual void show_statistics();
    void set_out_message(string message) {this->out_message = move(message);}
    string get_in_message() {return in_message;}
    string get_out_message() {return out_message;}
    void set_show(bool show) {this->show = show;}
};

#endif //CIFEPROJECT_CRYPTOR_H
