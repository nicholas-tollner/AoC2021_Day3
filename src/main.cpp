//
// Created by Nickt on 23/05/2022.
//
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Functions.h"
#include "Board.h"

int main(int argc, char *argv[])
{
    std::string line;
    std::ifstream inFile("src/resources/day_4_input_1.txt");

    std::vector<std::string> vec;
    std::vector<std::string> strings;
    std::vector<Board> boards;

    int boardCount = 0;

    // Check file could be opened
    if (!inFile)
    {
        std::cout << "File could not be opened" << std::endl;
        return 1;
    }
    getline(inFile, line);

    // Split string of numbers into vector
    Functions::stringSplit(line, ',', vec);
    Functions::gotoLine(inFile, 2);

    while(getline(inFile, line))
    {
        if (!line.empty())
        {
            strings.push_back(line);

            // When 5 lines have been read, create
            if (strings.size() == 5)
            {
                boards.push_back(Board(strings));
                strings.clear();
            }
        }
    }

    for (int i = 0; i < boards.size(); i++)
    {
        boards[i].print();
    }

    inFile.close();
    return 0;
}
