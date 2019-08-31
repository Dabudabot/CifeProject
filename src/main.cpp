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

#include "cryptors/Cryptor.h"

using namespace std;

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

int main(int argc, char *argv[]) {

    if (argc == 4) {
        try {
            auto cryptor = Cryptor::cryptor_factory(argv[1], argv[2], argv[3]);
            cryptor->run();
            cryptor->show_statistics();
        } catch (const exception &e) {
            cerr << e.what() << endl;
            show_usage();
            return 2;
        }
    } else {
        show_usage();
        return 1;
    }

    return 0;
}