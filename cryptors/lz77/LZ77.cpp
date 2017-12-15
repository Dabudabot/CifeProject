//
// Created by dabudabot on 15.12.17.
//

#include "LZ77.h"

constexpr char LEFT_BREAK = '[';
constexpr char RIGHT_BREAK = ']';
constexpr char SEPARATOR = ',';

void LZ77Encoder::run() {
    cout << "LZ77 encryption..." << endl;

    //iterate through message & write it into table
    vector<LZ77Node> table;
    for (int i = 0; i < get_in_message().length(); i++) {

        //initial data
        int amount = 0;
        int shift = 0;
        int initial_i = i;
        char symbol = get_in_message()[i];

        //iterate through encoded sequence
        for (int j = i; j >= 0; j--) {

            int temp_amount = 0;
            int temp_shift = 0;
            int initial_j = j;

            while (initial_i < get_in_message().length() &&
                   get_in_message()[initial_i] == get_in_message()[initial_j] &&
                    initial_j < i) {

                initial_i++;
                initial_j++;
                temp_amount++;

                if (temp_shift == 0) {
                    //relative offset
                    temp_shift = i - j;
                }
            }

            //no reason to refer if repetition is less than 4 chars
            if (temp_amount > amount && temp_amount > 3) {
                amount = temp_amount;
                shift = temp_shift;
            } else {
                initial_i = i;
            }
        }

        i += amount;
        symbol = get_in_message()[i];
        table.emplace_back(symbol, shift, amount);
    }

    stringstream out;
    for (LZ77Node &node : table) {
        if (node.get_offset() != 0 && node.get_amount() != 0) {
            out << LEFT_BREAK << node.get_offset() << SEPARATOR << node.get_amount() << RIGHT_BREAK << flush;
        }
        out << node.get_symbol() << flush;
    }
    set_out_message(out.str());

    cout << "encryption done!" << endl;
}

void LZ77Decoder::run() {
    cout << "LZ77 decryption..." << endl;

    stringstream output;

    for (int i = 0; i < get_in_message().length(); i++) {
        if (get_in_message()[i] == LEFT_BREAK) {
            i++;

            stringstream offset_s;
            stringstream amount_s;
            while (get_in_message()[i] != SEPARATOR) {
                offset_s << get_in_message()[i] << flush;
                i++;
            }
            i++;
            while (get_in_message()[i] != RIGHT_BREAK) {
                amount_s << get_in_message()[i] << flush;
                i++;
            }

            int offset = stoi(offset_s.str());
            int amount = stoi(amount_s.str());
            int len = static_cast<int>(output.str().length());

            output << output.str().substr(static_cast<unsigned long>(len - offset),
                                          static_cast<unsigned long>(amount)) << flush;
        } else {
            output << get_in_message()[i] << flush;
        }
    }

    set_out_message(output.str());

    cout << "decryption done." << endl;
}
