// Standard Library includes
#include <iostream>
#include <vector>
#include <string>

// Our project headers
#include "CaesarCipher.hpp"

CaesarCipher::CaesarCipher(const size_t keyValue)
    : key_{keyValue} //,
//alphabet_{'A', 'B'}
{
}
CaesarCipher::CaesarCipher(const std::string &keyString)
    : key_{0}
{
  if (!keyString.empty())
  {
    for (const auto &elem : keyString)
    {
      if (!std::isdigit(elem))
      {
        std::cerr << "[error] cipher key must be an unsigned long integer for Caesar cipher,\n"
                  << "        the supplied key (" << keyString << ") could not be successfully converted" << std::endl;
        return;
      }
    }
    key_ = std::stoul(keyString);
  }
}
std::string CaesarCipher::applyCipher(const std::string &inputText, const bool encrypt) const
  {
    std::string outputText{};
    //const std::vector<char> alphabet = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    const size_t alphabetSize = alphabet_.size();

    const size_t truncatedKey{key_ % alphabetSize};

    // Loop over the input text
    char processedChar{'x'};
    for (const auto &origChar : inputText)
    {

      for (size_t i{0}; i < alphabetSize; ++i)
      {

        if (origChar == alphabet_[i])
        {

          if (encrypt)
          {
            processedChar = alphabet_[(i + truncatedKey) % alphabetSize];
          }
          else
          {
            processedChar = alphabet_[(i + alphabetSize - truncatedKey) % alphabetSize];
          }
          break;
        }
      }
      outputText += processedChar;
    }
    return outputText;
  }
