//
// Created by Nickt on 24/05/2022.
//

#include <iostream>
#include <sstream>
#include "Board.h"
#include "Functions.h"

Board::Board(std::vector<std::string>& lines) {
    int count = 0;
    for (auto it = lines.begin(); it != lines.end(); it++)
    {
        // pass *it to parseSplit()  (just single line)
        // parseSplit() splits and parses string into row array
        // store row array in columns array
        parseSplit(*it, ' ', row);
        numbers[count] = row;
        count++;
    }
}

void Board::parseSplit(std::string line, char delimiter, std::array<int, 5> &arr) {
    std::vector<std::string> vec;
    int count = 0;

    Functions::stringSplit(line, delimiter, vec);

    for (auto it = vec.begin(); it != vec.end(); it++)
    {
        arr[count] = std::stoi((std::string) *it);
        count++;
    }
}

void Board::print() {
    for (int i = 0; i < numbers.size(); i++)
    {
        for (int j = 0; j < row.size(); j++)
        {
            std::cout << numbers[i][j] << " ";
        }
        std::cout << "\n";
    }
}