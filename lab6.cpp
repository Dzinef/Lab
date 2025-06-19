#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cctype>

const int MAX_LEN = 301;
const char* delimiters = " ,.;:!?\"'()[]{}<>\\|/\n\t";

bool Is_digits(const char* word) {
    for (int i{}; word[i]; ++i) {
        if (!std::isdigit(static_cast<unsigned char>(word[i])))
            return false;
    }
    return true;
}

bool Is_letters(const char* word) {
    for (int i{}; word[i]; ++i) {
        if (!std::isalpha(static_cast<unsigned char>(word[i])))
            return false;
    }
    return true;
}

void Reverse_word(char* word) {
    int size = std::strlen(word);
    for (int i{}; i < size / 2; ++i) {
        char temp = word[i];
        word[i] = word[size - i - 1];
        word[size - i - 1] = temp;
    }
}

void Add_zeros(const char* src, char* dest) {
    int size = std::strlen(src);
    int pad = 5 - size;
    for (int i = 0; i < pad; ++i)
        dest[i] = '0';
    std::strcpy(dest + pad, src);
}

bool Is_delim(char c) {
    return std::strchr(delimiters, c) != nullptr;
}

int main() {
    char input[MAX_LEN];
    char result[MAX_LEN * 2] = ""; 
    std::cout << "Input string:\n";
    std::cin.getline(input, MAX_LEN);
    char* p = input;
    bool first_word = true;
    while (*p) {
        while (*p && Is_delim(*p)) ++p;
        if (!*p) break;
        char word[301] = "";
        int i{};
        while (*p && !Is_delim(*p) && i < 300) {
            word[i++] = *p;
            ++p;
        }
        word[i] = '\0';
        char processed[301] = "";
        if (Is_digits(word) && std::strlen(word) < 5) {
            Add_zeros(word, processed);
        }
        else if (Is_letters(word)) {
            std::strcpy(processed, word);
            Reverse_word(processed);
        }
        else {
            std::strcpy(processed, word);
        }
        if (!first_word)
            std::strcat(result, " ");
        std::strcat(result, processed);
        first_word = false;
    }
    if (std::strlen(result) == 0) {
        std::cout << "Have no words to proccesed.\n";
    }
    else {
        std::cout << "Result:\n" << result << std::endl;
    }
    return 0;
}