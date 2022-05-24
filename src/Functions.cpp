//
// Created by Nickt on 24/05/2022.
//

#include <iostream>
#include <sstream>
#include <vector>
#include "Functions.h"

/**
 * Splits a string around a given delimiter into provided vector
 * @param line The string to split
 * @param delimiter The char to split around
 * @param vec The vector<std::string> to fill with split strings
 */
void Functions::stringSplit(std::string line, char delimiter, std::vector<std::string> &vec) {
    std::stringstream stream(line);
    std::string token;

    while (std::getline(stream, token, delimiter)) {
        vec.push_back(token);
    }
}


