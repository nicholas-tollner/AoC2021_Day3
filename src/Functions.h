//
// Created by Nickt on 24/05/2022.
//
#ifndef AOC2021_DAY3_FUNCTIONS_H
#define AOC2021_DAY3_FUNCTIONS_H

#include <string>


class Functions {
public:
    static void stringSplit(std::string line, char delimiter, std::vector<std::string>& vec);
    static std::ifstream& gotoLine(std::ifstream& file, unsigned int skip);
};


#endif //AOC2021_DAY3_FUNCTIONS_H
