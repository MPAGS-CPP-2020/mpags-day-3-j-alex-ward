#ifndef MPAGSCIPHER_CaesarCipher_HPP
#define MPAGSCIPHER_CaesarCipher_HPP

#include <string>
#include <vector>

class CaesarCipher{
  public:
    CaesarCipher(const std::string& keyValue);

    std::string key; //Cipher key
};

#endif // MPAGSCIPHER_CaesarCipher_HPP 
