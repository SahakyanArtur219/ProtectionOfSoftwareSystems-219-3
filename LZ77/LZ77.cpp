#include <iostream>
#include <vector>
#include <string>

struct Match {
    int offset;
    int length;
    char nextChar;
};

std::vector<Match> lz77_compress(const std::string& input, int windowSize, int lookaheadBufferSize) {
    std::vector<Match> compressedData;
    int inputSize = input.size();
    int pos = 0;

    while (pos < inputSize) {
        int matchLength = 0;
        int matchOffset = 0;
        char nextChar = input[pos];

        for (int i = std::max(0, pos - windowSize); i < pos; ++i) {
            int length = 0;
            while (length < lookaheadBufferSize && pos + length < inputSize && input[i + length] == input[pos + length]) {
                ++length;
            }
            if (length > matchLength) {
                matchLength = length;
                matchOffset = pos - i;
                if (pos + length < inputSize) {
                    nextChar = input[pos + length];
                }
            }
        }

        compressedData.push_back({ matchOffset, matchLength, nextChar });
        pos += matchLength + 1;
    }

    return compressedData;
}

int main() {
    std::string input = "aacaacabcabaaac";
    int windowSize = 6;
    int lookaheadBufferSize = 4;

    std::vector<Match> compressedData = lz77_compress(input, windowSize, lookaheadBufferSize);

    for (const auto& match : compressedData) {
        std::cout << "(" << match.offset << ", " << match.length << ", " << match.nextChar << ")\n";
    }

    return 0;
}
