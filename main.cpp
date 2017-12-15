/*
 * created by dabudabot on 14.12.17
 *
 * Cipher program to encrypt\decrypt using
 * - Huffman
 * - LZ77
 * - Deflate
 *
 * usage:
 *  <CifeProject> -e Huffman "text_to_encrypt"
 *  <CifeProject> -d Huffman "text_to_encrypt"
 *
 *
 *  <CifeProject> -e LZ77 "text_to_encrypt"
 *  <CifeProject> -d LZ77 "text_to_encrypt"
 *
 *  <CifeProject> -e Deflate "text_to_encrypt"
 *  <CifeProject> -d Deflate "text_to_encrypt"
 */

#include "utils/helper.h"

using namespace std;

int main(int argc, char *argv[]) {

    if (argc == 4) {
        try {
            auto cryptor = helper::cryptor_factory(argv[1], argv[2], argv[3]);
            cryptor->run();
            cryptor->show_statistics();
        } catch (const exception &e) {
            cerr << e.what() << endl;
            helper::show_usage();
            return 2;
        }
    } else {
        helper::show_usage();
        return 1;
    }

    return 0;
}