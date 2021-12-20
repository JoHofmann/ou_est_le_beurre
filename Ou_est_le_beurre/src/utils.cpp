//
// Created by paddy on 06.12.21.
//

#include "ou_est_le_beurre/utils.hpp"
#include <sstream>

std::vector<std::wstring> utils::split(const std::wstring& s, wchar_t delimiter)
{
    std::vector<std::wstring> tokens;
    std::wstring token;
    std::wstringstream tokenStream(s);
    while (std::getline(tokenStream, token, delimiter))
    {
        tokens.push_back(token);
    }
    return tokens;
}