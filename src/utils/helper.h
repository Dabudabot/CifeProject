//
// Created by dabudabot on 14.12.17.
//
// Helper

#pragma once

#include "../cryptors/huffman/Huffman.h"
#include "../cryptors/lz77/LZ77.h"
#include "../cryptors/deflate/Deflate.h"

namespace helper {

    using namespace std;

    /*
     * All constant keys kept here
     */
    constexpr char ENCRYPT_KEY[] = "-e";
    constexpr char DECRYPT_KEY[] = "-d";
    constexpr char HUFFMAN_KEY[] = "Huffman";
    constexpr char LZW_KEY[] = "lzw";
    constexpr char LZ77_KEY[] = "LZ77";
    constexpr char DEFLATE_KEY[] = "Deflate";

    /*
     * help message for dummies
     */
    void show_usage() {
        cout << "usage: " << endl;
        cout << "  <CifeProject> " << ENCRYPT_KEY << " "
             << HUFFMAN_KEY << " \"text_to_encrypt\"" << endl;
        cout << "  <CifeProject> " << DECRYPT_KEY << " "
             << HUFFMAN_KEY << " \"text_to_decrypt\"" << endl;

        cout << "  <CifeProject> " << ENCRYPT_KEY << " "
             << LZW_KEY << " \"text_to_encrypt\"" << endl;
        cout << "  <CifeProject> " << DECRYPT_KEY << " "
             << LZW_KEY << " \"text_to_decrypt\"" << endl;

        cout << "  <CifeProject> " << ENCRYPT_KEY << " "
             << LZ77_KEY << " \"text_to_encrypt\"" << endl;
        cout << "  <CifeProject> " << DECRYPT_KEY << " "
             << LZ77_KEY << " \"text_to_decrypt\"" << endl;

        cout << "  <CifeProject> " << ENCRYPT_KEY << " "
             << DEFLATE_KEY << " \"text_to_encrypt\"" << endl;
        cout << "  <CifeProject> " << DECRYPT_KEY << " "
             << DEFLATE_KEY << " \"text_to_decrypt\"" << endl;
    }

    /*
     * Factory method to get correct cryption algorithm depending on mode and type
     */
    unique_ptr<Cryptor> cryptor_factory(const string &mode,
                                        const string &type,
                                        const string &message) {
        if (mode == ENCRYPT_KEY &&
            type == HUFFMAN_KEY) {
            return unique_ptr<Cryptor>(new HuffmanEncoder(message));
        } else if (mode == DECRYPT_KEY &&
                   type == HUFFMAN_KEY) {
            return unique_ptr<Cryptor>(new HuffmanDecoder(message));

        } else if (mode == ENCRYPT_KEY &&
                   type == LZ77_KEY) {
            return unique_ptr<Cryptor>(new LZ77Encoder(message));
        } else if (mode == DECRYPT_KEY &&
                   type == LZ77_KEY) {
            return unique_ptr<Cryptor>(new LZ77Decoder(message));

        } else if (mode == ENCRYPT_KEY &&
                   type == DEFLATE_KEY) {
            return unique_ptr<Cryptor>(new DeflateEncoder(message));
        } else if (mode == DECRYPT_KEY &&
                   type == DEFLATE_KEY) {
            return unique_ptr<Cryptor>(new DeflateDecoder(message));
        } else {
            throw exception();
        }
    }
}
