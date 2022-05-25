//
// Created by Nickt on 24/05/2022.
//

#ifndef AOC2021_DAY4_BOARD_H
#define AOC2021_DAY4_BOARD_H

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
    explicit Board(std::vector<std::string> &lines, int boardNo);

    static void parseSplit(std::string line, char delimiter, std::array<int, 5> &arr);
    void checkMatch(unsigned int num);
    void print();
    void printMatch();
    bool checkBingo();
    bool hasWon();
    int sumUnmatched();

    int getBoardNo();

private:
    std::array<std::array<int, 5>, 5> numbers = {};  // Array of arrays
    std::array<std::array<bool, 5>, 5> marked = {};  // Array of arrays
    std::array<int, 5> row = {};
    int boardNo;
    bool won = false;
};

#endif //AOC2021_DAY4_BOARD_H
