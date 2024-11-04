#include <iostream>
#include "MixEncryptionAndDecryption.h"


int main()
{
    MixEncriptionAndDecription MEAD(10);

    string message;
    cout << "Input the text that need to encrypt and decrypt text = ";
    cin >> message;

    message = MEAD.Encrypt(message);
    
    cout <<"Encrypted text is this ->>>>>   "<< message << "\n";

    message = MEAD.Decrypt(message);

    cout << "Decrypted text is this ->>>>>   " << message << "\n";
}

