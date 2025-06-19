#include <iostream>
#include <string>
#include <cctype>

bool Is_digits(const std::string& word) {
    for (std::size_t i{}; i < word.length(); ++i) {
        if (!std::isdigit(static_cast<unsigned char>(word[i])))
            return false;
    }
    return true;
}

int Count_zeros(const std::string& word) {
    int counter{};
    for (std::size_t i{}; i < word.length(); ++i) {
        if (word[i] == '0') 
            ++counter;
    }
    return counter;
}

int main() {
    try {
        std::string input;
        std::cout << "Enter string:\n";
        std::getline(std::cin, input);
        std::string max1 = "", max2 = "";
        int max_zero_count = -1;
        std::size_t len = input.length();
        for (std::size_t i{}; i < len;) {
            for (; i < len && std::isspace(static_cast<unsigned char>(input[i])); ++i);
            std::size_t start = i;
            for (; i < len && !std::isspace(static_cast<unsigned char>(input[i])); ++i);
            if (start < i) {
                std::string word = input.substr(start, i - start);
                if (Is_digits(word)) {
                    int zeros = Count_zeros(word);
                    if (zeros > max_zero_count) {
                        max_zero_count = zeros;
                        max2 = "";
                        max1 = word;
                    }
                    else if (zeros == max_zero_count) {
                        max2 = max1;
                        max1 = word;
                    }
                }
            }
        }
        if (max_zero_count == -1) {
            throw "No needed words.";
        }
        if (max2.empty()) {
            std::cout << "Word with max nulls: " << max1 << std::endl;
        }
        else {
            std::cout << "Word before word with max nulls: " << max2 << std::endl;
        }
    }
    catch (const char* msg) {
        std::cerr << "Error: " << msg << std::endl;
    }
    return 0;
}