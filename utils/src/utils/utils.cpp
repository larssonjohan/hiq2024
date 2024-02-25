#include "utils/utils.h"

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

namespace hiq {
namespace utils {

std::string askInput()
{
    std::string input{};
    std::getline(std::cin, input);

    return input;
}

std::vector<std::string> splitInput(const std::string& input,
                                    const char delim)
{
    std::vector<std::string> tokens{};
    
    std::stringstream ss(input);
    std::string token{};
    while(std::getline(ss, token, delim))
    {
        tokens.emplace_back(std::move(token));
    }

    return tokens;
}

} // namespace utils
} // namespace hiq
