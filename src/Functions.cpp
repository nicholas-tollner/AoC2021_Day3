//
// Created by Nickt on 24/05/2022.
//
#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>
#include "Functions.h"

/**
 * Splits a string around a given delimiter into provided vector
 * @param line The string to split
 * @param delimiter The char to split around
 * @param vec The vector<std::string> to fill with split strings
 */
void Functions::stringSplit(std::string line, char delimiter, std::vector<std::string>& vec) {
    std::stringstream stream(line);
    std::string token;

    while (std::getline(stream, token, delimiter)) {
        vec.push_back(token);
    }
}

/**
 * Skips a number of lines in a given file
 * @param file The file to move in
 * @param skip The number of lines to skip
 * @return The original file
 */
std::ifstream& Functions::gotoLine(std::ifstream& file, unsigned int skip) {
    if (!file)
    {
        std::cout << "File could not be opened" << std::endl;
        exit(1);
    }
    file.seekg(std::ios_base::beg);                     // Set next character to be extracted to beginning of file

    // Skip lines
    for (int i = 0; i < skip; i++)
    {
        file.ignore(INT_MAX, '\n');            // Read in and discard characters until delimiter is reached
    }
    return file;
}


