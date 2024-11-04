#include <iostream>
#include <string>
using namespace std;

class CaesarCipher {
private:
	int shift;

public:
	CaesarCipher(int k) : shift(k % 26) {}

	string encrypt(const string& text) {
		string result = "";

		for (char ch : text) {
			if (isalpha(ch)) {
				char offset = isupper(ch) ? 'A' : 'a';
				result += (ch - offset + shift) % 26 + offset;
			}
			else {
				result += ch;
			}
		}
		return result;
	}

	string decrypt(const string& text) {
		string result = "";

		for (char ch : text) {
			if (isalpha(ch)) {
				char offset = isupper(ch) ? 'A' : 'a';
				result += (ch - offset - shift + 26) % 26 + offset;
			}
			else {
				result += ch;
			}
		}
		return result;
	}
};
