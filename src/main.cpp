//
// Created by Nickt on 23/05/2022.
//
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Functions.h"

int main(int argc, char *argv[])
{
    std::string line;
    std::ifstream inFile("src/resources/day_4_input_1.txt");
    std::vector<std::string> vec;

    // Check file could be opened
    if (!inFile)
    {
        std::cout << "File could not be opened" << std::endl;
        return 1;
    }
    getline(inFile, line);
    std::cout << line << std::endl << std::endl;

    Functions::stringSplit(line, ',', vec);

    for (auto it = vec.begin(); it != vec.end(); it++)
    {
        std::cout << *it << " ";
    }

    inFile.close();
    return 0;
}
