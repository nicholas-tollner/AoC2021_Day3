//
// Created by Nickt on 24/05/2022.
//

#include <iostream>
#include <sstream>
#include "Functions.h"

/**
 * Splits a string around a given delimiter. Allocates appropriate memory to accommodate given string.
 * @param line The String to split
 * @param delimiter The char to split around
 * @return Pointer to memory containing first split String
 */
std::string *Functions::stringSplit(std::string line, const char &delimiter) {
    std::stringstream stream(line);
    std::string token;

    std::string* temp = (std::string*) malloc(line.size() * sizeof(line));
    std::string* ptr = temp;

    while (std::getline(stream, token, delimiter)) {
        *temp = token;
        temp++;
    }
    return ptr;
}


