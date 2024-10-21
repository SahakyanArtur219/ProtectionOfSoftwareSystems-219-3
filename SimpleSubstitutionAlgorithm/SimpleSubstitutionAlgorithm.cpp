#include <iostream>
#include <cstring>

const char* alphabet = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";

void encrypt(char text[], const char alphabet[]) {
    for (int i = 0; i < strlen(text); ++i) {
        if (text[i] >= 'a' && text[i] <= 'z') {
            text[i] = alphabet[text[i] - 'a' + 26];
        }
        else if (text[i] >= 'A' && text[i] <= 'Z') {
            text[i] = alphabet[text[i] - 'A'];
        }
    }
}

int main() {

    char text[100];

    std::cout << "Enter text to encrypt: ";
    std::cin.getline(text, 100);

    encrypt(text, alphabet);

    std::cout << "Encrypted text: " << text << std::endl;

    return 0;
}
