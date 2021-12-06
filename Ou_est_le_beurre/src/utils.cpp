//
// Created by paddy on 06.12.21.
//

#include "ou_est_le_beurre/utils.hpp"
#include <sstream>

std::vector<std::string> utils::split(const std::string& s, char delimiter)
{
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(s);
    while (std::getline(tokenStream, token, delimiter))
    {
        tokens.push_back(token);
    }
    return tokens;
}