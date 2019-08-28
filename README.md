![travis-ci.org](https://api.travis-ci.org/Dabudabot/CifeProject.png "CifeProject build status")
[![codecov.io](https://codecov.io/github/Dabudabot/CifeProject/coverage.svg?branch=master)](https://codecov.io/github/Dabudabot/CifeProject?branch=master)
# CifeProject
Implemetation of different encryption\decryption algorithms
test
 - Huffman
 - LZ77
 - Deflate
 
 * usage:
 *  <CifeProject> -e Huffman "text_to_encrypt"
 *  <CifeProject> -d Huffman "text_to_encrypt"
 *
 *  <CifeProject> -e LZ77 "text_to_encrypt"
 *  <CifeProject> -d LZ77 "text_to_encrypt"
 *
 *  <CifeProject> -e Deflate "text_to_encrypt"
 *  <CifeProject> -d Deflate "text_to_encrypt"
 
 Huffman encoding
 * encoded sequence is represented as:
 * n = 1 byte long number - dictionary length
 * n times 1 byte long char and 1 byte long frequency
 * finally encoded message
 
 LZ77 encoding
 * encoded sequence is represented as:
 * sequence of chars and [Offset,Lenght] <- reference
