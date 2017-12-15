//
// Created by dabudabot on 15.12.17.
//

#include "Cryptor.h"

void Cryptor::show_statistics() {
    string s;
    string s2;
    cout << "---------------" << endl;
    cout << "input message: " << endl;
    cout << " " << get_in_message() << endl;
    if (get_in_message().find_first_not_of("01") != string::npos) {
        cout << "or binary: " << endl;
        stringstream ss;
        for (char i : get_in_message()) {
            ss << bitset<8>(static_cast<unsigned long long int>(i)) << flush;
        }
        s = ss.str();
        cout << " " << s << endl;
    }
    cout << endl;

    cout << "output: " << endl;
    cout << " " << get_out_message() << endl;
    if (get_out_message().find_first_not_of("01") != string::npos) {
        cout << "or binary: " << endl;
        stringstream ss2;
        for (char i : get_out_message()) {
            ss2 << bitset<8>(static_cast<unsigned long long int>(i)) << flush;
        }
        s2 = ss2.str();
        cout << " " << s2 << endl;
    } else {
        s2 = get_out_message();
    }
    cout << "---------------" << endl;

    if (show) {
        auto diff = s.size() - s2.size();
        auto compression = (diff * 100.0) / s.size();
        cout << "compression: " << compression << "%" << endl;
        cout << "---------------" << endl;
    }
}