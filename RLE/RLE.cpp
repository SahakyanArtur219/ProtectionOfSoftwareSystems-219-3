#include <iostream>
#include <string>

int RLE(const std::string& input, unsigned char* encoded) {
	int c = 0;
	for (int i = 0; i < input.length(); i++) {
		int count = 1;
		while (i < input.length() - 1 && input[i] == input[i + 1]) {
			count++;
			i++;
			if (count == 256) {
				break;
			}
		}
		encoded[2 * c] = input[i];
		encoded[2 * c + 1] = count - 1;
		c++;
	}
	return 2 * c - 2;
}

int main() {

	unsigned char data[100];

	std::string T = "aasssffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffawdddddddssssss555555";
	int length = RLE(T, data);

	std::cout << "Original string: " << T << std::endl;

	for (int i = 0; i < length; i += 2) {
		std::cout << data[i] << (int)data[i + 1];
	}

}