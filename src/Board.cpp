//
// Created by Nickt on 24/05/2022.
//

#include <iostream>
#include "Board.h"
#include "Functions.h"

/**
 * Constructor for Board class
 * @param lines The string containing elements to populate numbers array
 */
Board::Board(std::vector<std::string>& lines) {
    int count = 0;
    for (auto it = lines.begin(); it != lines.end(); it++)
    {
        parseSplit(*it, ' ', row);
        numbers[count] = row;
        count++;
    }
}

/**
 * Splits a string along a delimiter, converts split strings into ints and stores in arr
 * @param line The string to split
 * @param delimiter The delimiter to split around
 * @param arr The array to store split ints in
 */
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

/**
 * Prints out all numbers in Board
 */
void Board::print() {
    for (int i = 0; i < numbers.size(); i++)
    {
        for (int j = 0; j < row.size(); j++)
        {
            std::cout << numbers[i][j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}