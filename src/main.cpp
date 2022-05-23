//
// Created by Nickt on 23/05/2022.
//
#include <iostream>
#include <fstream>
#include <string>
#include "Functions.h"

int main(int argc, char *argv[])
{
    std::string line;
    std::ifstream inFile("src/resources/day_4_input_1.txt");

    // Check file could be opened
    if (!inFile)
    {
        std::cout << "File could not be opened" << std::endl;
        return 1;
    }
    getline(inFile, line);
    std::cout << line << std::endl << std::endl;

    std::string* ptr = Functions::stringSplit(line, ',');

    std::cout << "Current Ptr Value: " << *ptr++ << std::endl;

    inFile.close();
    return 0;
}
