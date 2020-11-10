// Standard Library includes
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "CaesarCipher.cpp"

TEST_CASE("Truncated key is withing alphabet range", "[numeric]")
{   
    const std::vector<char> alphabet = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    const size_t alphabetSize = alphabet.size();
    REQUIRE(alphabetSize == 26);
    for(int n=0; n<10; n++){
        int key{rand() % 50};
        REQUIRE(key == (int)key);
        const size_t truncatedKey{key % alphabetSize};
        int i{rand() % 25};
        SECTION("Key is Encryption (+ve shift)"){
            REQUIRE((i + truncatedKey) % alphabetSize <= 25);
            const char letter{alphabet[(i + truncatedKey) % alphabetSize] };
            REQUIRE(std::find(alphabet.begin(), alphabet.end(), letter) != alphabet.end());
        }
        SECTION("Key is Decryption (-ve shift)"){
            key = -key;
            REQUIRE((i + alphabetSize - truncatedKey) % alphabetSize <= 25);
            const char letter{alphabet[(i + alphabetSize - truncatedKey) % alphabetSize]};
            REQUIRE(std::find(alphabet.begin(), alphabet.end(), letter) != alphabet.end());
        }
    }
}