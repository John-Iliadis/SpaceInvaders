//
// Created by Gianni on 29/12/2023.
//

#include "../include/high_scores.hpp"

std::vector<std::pair<std::string, int>> HighScores::scores_list;

void HighScores::init()
{
    std::ifstream input_settings_file("../data/high_scores.json");

    if (!input_settings_file.is_open())
    {
        throw std::runtime_error("HighScores::init - Failed to load settings file");
    }

    json high_scores;

    high_scores = json::parse(input_settings_file);

    scores_list.reserve(high_scores["high_scores"].size());

    for (const auto& entry : high_scores["high_scores"])
    {
        std::string name = entry["name"].get<std::string>();
        int score = entry["score"];

        std::transform(name.begin(), name.end(), name.begin(), ::toupper);

        scores_list.emplace_back(name, score);
    }

    std::sort(scores_list.begin(), scores_list.end(),
              [] (const auto& a, const auto& b) {
                  return a.second > b.second;
    });

    scores_list.erase(scores_list.begin() + 10, scores_list.end());

    input_settings_file.close();
}

void HighScores::save()
{
    std::ofstream output_settings_file("../data/high_scores.json", std::ios::trunc);

    if (!output_settings_file.is_open())
    {
        throw std::runtime_error("HighScores::save - Failed to load settings file");
    }

    json high_scores_array;

    for (const auto& [name, score] : scores_list)
    {
        json score_object;
        score_object["name"] = name;
        score_object["score"] = score;
        high_scores_array.push_back(score_object);
    }

    json json_object;
    json_object["high_scores"] = high_scores_array;

    output_settings_file << std::setw(4) << json_object;

    output_settings_file.close();
}

void HighScores::add_score(std::string name, int score)
{
    if (scores_list.back().second > score) return;

    auto itr = std::lower_bound(scores_list.begin(), scores_list.end(), score,
                                [] (const auto& a, int score) {
                                    return a.second > score;
    });

    std::transform(name.begin(), name.end(), name.begin(), ::toupper);

    scores_list.emplace(itr, name, score);
}

const std::vector<std::pair<std::string, int>>& HighScores::get_scores()
{
    return scores_list;
}
