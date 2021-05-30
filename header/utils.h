#pragma once
#include <string>
#include <vector>

namespace deep_learning{

    namespace utils{

        std::vector<std::string> split (const std::string& s, const std::string& delimiter);
        void print(const std::string& msg);

    };
};