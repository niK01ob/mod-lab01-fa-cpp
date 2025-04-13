// Copyright 2022 UNN-IASR
#include "fun.h"

#include <cmath>
#include <cctype>

unsigned int faStr1(const char* str) {
    unsigned int count = 0;
    bool inWord = false;
    bool containsDigit = false;
    while (*str) {
        if (!std::isspace(*str) && !inWord) {
            count++;
            inWord = true;
            containsDigit = false;
        }
        if (std::isdigit(*str)) {
            count -= containsDigit ? 0 : 1;
            containsDigit = true;
        }
        if (std::isspace(*str) && inWord) {
            containsDigit = false;
            inWord = false;
        }
        str++;
    }
    return count;
}

unsigned int faStr2(const char* str) {
    unsigned int count = 0;
    bool inWord = false;
    bool isValidated = false;
    while (*str) {
        if (std::isspace(*str) && inWord) {
            isValidated = false;
            inWord = false;
        } else if (!std::islower(*str)) {
            count -= isValidated ? 1 : 0;
            isValidated = false;
        } else if (!inWord && std::isupper(*str)) {
            count++;
            inWord = true;
            isValidated = true;
        } else {
            inWord = true;
        }
        str++;
    }
    return count;
}

unsigned int faStr3(const char* str) {
    unsigned int count = 0;
    size_t lenWords = 0;
    bool inWord = false;
    while (*str) {
        if (std::isspace(*str) && inWord) {
            inWord = false;
        } else if (!std::isspace(*str) && !inWord) {
            inWord = true;
            count++;
            lenWords++;
        } else if (!std::isspace(*str) && inWord) {
            lenWords++;
        }
        str++;
    }
    if (count == 0) {
        return 0;
    }
    return count == 0 ? 0 : std::round(static_cast<double>(lenWords) / count);
}
