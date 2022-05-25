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

    int boardsWon = 0;
    int count = 1;

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

            // When 5 lines have been read, add new Board object to boards array
            if (strings.size() == 5)
            {
                boards.push_back(Board(strings, count));
                strings.clear();
                count++;
            }
        }
    }

    // Iterate through vector of strings
    for (int i = 0; i < vec.size(); i++)
    {
        int num = std::stoi(vec[i]);

        // Check if current number matches
        for (int i = 0; i < boards.size(); i++)
        {
            if (!boards[i].hasWon()) {
                boards[i].checkMatch(num);
            }
//           Part One Solution
//            if (boards[i].checkBingo(num))
//            {
//                std::cout << "Bingo on board: " << i+1 << std::endl;
//                std::cout << "Last called number: " << num << std::endl;
//                int sum = boards[i].sumUnmatched();
//                std::cout << "Sum of unmatched numbers: " << sum << std::endl;
//                std::cout << "Final score: " << sum * num << std::endl;
//                return 0;
//            }
            if (!boards[i].hasWon()) {
                if (boards[i].checkBingo()) {
                    boardsWon++;
                    std::cout << "Boards remaining: " << boards.size() - boardsWon << ", Num: " << num << std::endl;
                }
            }

            if (boardsWon == boards.size())
            {
                std::cout << "Last to win: " << boards[i].getBoardNo() << std::endl;
                std::cout << "Last called number: " << num << std::endl;
                int sum = boards[i].sumUnmatched();
                std::cout << "Sum of unmatched numbers: " << sum << std::endl;
                std::cout << "Final score: " << sum * num << std::endl;
                return 0;
            }
        }
    }

    inFile.close();
    return 0;
}
