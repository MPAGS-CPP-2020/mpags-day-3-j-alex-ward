#ifndef MPAGSCIPHER_CaesarCipher_HPP
#define MPAGSCIPHER_CaesarCipher_HPP

#include <string>

class CaesarCipher{
  public:
    explicit CaesarCipher(const size_t keyValue);
    explicit CaesarCipher(const std::string& keyString);

    std::string applyCipher(const std::string& inputText, const bool encrypt) const;

  private:
    size_t key_; //Cipher key
    const std::vector<char> alphabet_ = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    
};

#endif // MPAGSCIPHER_CaesarCipher_HPP 
