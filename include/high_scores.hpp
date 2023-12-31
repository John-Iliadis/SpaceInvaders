//
// Created by Gianni on 29/12/2023.
//

#ifndef SPACEINVADERS_HIGH_SCORES_HPP
#define SPACEINVADERS_HIGH_SCORES_HPP

#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include "json.hpp"

class HighScores
{
public:
    static void init();
    static void save();

    static void add_score(std::string name, int score);

    static const std::vector<std::pair<std::string, int>>& get_scores();

private:
    static std::vector<std::pair<std::string, int>> scores_list;
};


#endif //SPACEINVADERS_HIGH_SCORES_HPP
