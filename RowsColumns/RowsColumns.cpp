#include "RowsColumns.h"

int main() {

    string text;

    cout << "Enter the text to encrypt: ";
    cin >> text;
   
    Crypto& c = *new TransposeCoder();

    string encryptedText = c.encrypt(text);
    cout << "Encrypted text: " << encryptedText << endl;

    string decryptedText = c.decrypt(encryptedText);
    cout << "Decrypted text: " << decryptedText << endl;

    delete& c;

    return 0;
}