//
// Created by Nickt on 24/05/2022.
//
#ifndef AOC2021_DAY3_FUNCTIONS_H
#define AOC2021_DAY3_FUNCTIONS_H

#include <string>


class Functions {
public:
    static std::string* stringSplit(std::string line, const std::string& delimiter);
    static std::string* stringSplit(std::string line, const char& delimiter);
};


#endif //AOC2021_DAY3_FUNCTIONS_H
