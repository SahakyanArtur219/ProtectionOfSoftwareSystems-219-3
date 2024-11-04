#include "RowsColumns.h"
#include "Ceasar.h"
#include <iostream>
#include <memory>

class MixEncriptionAndDecription : public CaesarCipher, public TransposeCoder {
    int key;
    std::unique_ptr<TransposeCoder> c;
public:
    MixEncriptionAndDecription(int k) : CaesarCipher(k), key(k), c(std::make_unique<TransposeCoder>()) {}

    std::string Encrypt(std::string message) {
        std::string mix_message = CaesarCipher::encrypt(message);
        mix_message = c->encrypt(mix_message);
        return mix_message;
    }

    std::string Decrypt(std::string mix_message) {
        std::string message = c->decrypt(mix_message);
        message = CaesarCipher::decrypt(message);
        return message;
    }
};
