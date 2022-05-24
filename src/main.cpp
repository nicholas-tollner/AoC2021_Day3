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
    std::vector<std::string> boardStrings;

    // Check file could be opened
    if (!inFile)
    {
        std::cout << "File could not be opened" << std::endl;
        return 1;
    }
    getline(inFile, line);

    // Split string of numbers into vector
    Functions::stringSplit(line, ',', vec);

    for (auto it = vec.begin(); it != vec.end(); it++)
    {
        std::cout << *it << " ";
    }

    std::cout << "\n" << std::endl;
    Functions::gotoLine(inFile, 2);

    while(getline(inFile, line))
    {
        if (!line.empty())              // Check if line is empty
        {
            boardStrings.push_back(line);
            if (boardStrings.size() == 5)
            {
                std::cout << "Board full" << std::endl;
                break;
            }
        }
    }

    for (auto it = boardStrings.begin(); it != boardStrings.end(); it++)
    {
        std::cout << *it << std::endl;
    }

    std::cout <<  "\n";

    Board *board = new Board(boardStrings);

    board->print();


    inFile.close();
    return 0;
}
