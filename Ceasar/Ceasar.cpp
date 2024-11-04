#include "Ceasar.h"

int main() {
	int k;
	cout << "Enter shift (k): ";
	cin >> k;

	CaesarCipher cipher(k);

	string message;
	cout << "Enter message to encrypt: ";
	cin.ignore();
	getline(cin, message);

	string encrypted = cipher.encrypt(message);
	cout << "Encrypted message: " << encrypted << endl;

	string decrypted = cipher.decrypt(encrypted);
	cout << "Decrypted message: " << decrypted << endl;

	return 0;
}
