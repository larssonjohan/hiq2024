#pragma once

#include <string>
#include <vector>

namespace hiq {
namespace utils {

std::string askInput();
std::vector<std::string> splitInput(const std::string& input, const char delim);

} // namespace utils
} // namespace hiq
