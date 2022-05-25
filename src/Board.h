//
// Created by Nickt on 24/05/2022.
//

#ifndef AOC2021_DAY3_BOARD_H
#define AOC2021_DAY3_BOARD_H

#include <array>
#include <vector>

/**
     * X X X X X
     * X X X X X
     * X X X X X
     * X X X X X
     */
class Board {
public:
    explicit Board(std::vector<std::string> &lines);

    static void parseSplit(std::string line, char delimiter, std::array<int, 5> &arr);
    void checkMatch(unsigned int num);
    void print();
    void printMatch();

private:
    std::array<std::array<int, 5>, 5> numbers = {};  // Array of arrays
    std::array<std::array<bool, 5>, 5> marked = {};  // Array of arrays
    std::array<int, 5> row = {};
};

#endif //AOC2021_DAY3_BOARD_H
