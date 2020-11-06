// Standard Library includes
#include <iostream>

// Our project headers
#include "CaesarCipher.hpp"

CaesarCipher::CaesarCipher(const std::string& keyValue)
  :key{keyValue}
{
  key = keyValue;
}
