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
Board::Board(std::vector<std::string> &lines, int boardNo) {
    this->boardNo = boardNo;
    int count = 0;
    for (auto it = lines.begin(); it != lines.end(); it++) {
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

    for (auto it = vec.begin(); it != vec.end(); it++) {
        arr[count] = std::stoi((std::string) *it);
        count++;
    }
}

/**
 * Checks if a given number is present in the numbers array
 * Marks corresponding position in marked array if num is present
 * @param num The number to check for
 */
void Board::checkMatch(unsigned int num) {
    for (int i = 0; i < numbers.size(); i++) {
        for (int j = 0; j < row.size(); j++) {
            if (numbers[i][j] == num) {
                marked[i][j] = true;
                //std::cout << num << " matched board " << boardNo << std::endl;
            }
        }
    }
}

/**
 * Prints out all numbers in Board
 */
void Board::print() {
    for (int i = 0; i < numbers.size(); i++) {
        for (int j = 0; j < row.size(); j++) {
            std::cout << numbers[i][j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

/**
 * Prints out all matches in Board
 */
void Board::printMatch() {
    for (int i = 0; i < marked.size(); i++) {
        for (int j = 0; j < row.size(); j++) {
            std::cout << marked[i][j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

/**
 * Checks for completed rows and returns true if bingo has been achieved
 * @return true If bingo has been achieved, false otherwise
 */
bool Board::checkBingo(int num) {
    std::array<bool, 5> bingo = {};
    int rowNo = 0;

    for (int i = 0; i < 5; i++) {
        for (int pos = 0; pos < row.size(); pos++) {
            // If current position is not marked, move to next row
            if (!marked[rowNo][pos]) {
                rowNo++;
                bingo = {};         // Reset bingo array
                break;
            }
            bingo[pos] = true;

            if (pos == 4) {
                return true;
            }
        }
    }
    // Check columns for bingo
    for (int i = 0; i < marked.size(); i++) {
        // If first element in column is true, check entire column
        for (int j = 0; j < row.size(); j++) {
            if (!marked[i][j]) {
                bingo = {};
                break;
            }
            bingo[j] = true;

            if (j == 4) {
                return true;
            }
        }
    }
    for (int i = 0; i < bingo.size(); i++) {
        if (!bingo[i]) {
            return false;
        }
    }
    return true;
}

int Board::sumUnmatched() {
    int sum = 0;
    std::cout << "Summing: ";
    for (int i = 0; i < marked.size(); i++) {
        for (int j = 0; j < row.size(); j++) {
            if (!marked[i][j]) {
                std::cout << numbers[i][j] << " ";
                sum += numbers[i][j];
            }
        }
    }
    std::cout << "\n";
    return sum;
}



