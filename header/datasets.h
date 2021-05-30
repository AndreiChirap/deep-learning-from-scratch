#pragma once
#include <string>
#include <vector>

namespace deep_learning{
    
    namespace datasets{

        class Mnist{
            private:
                std::vector<std::vector<float>*>* digits = new std::vector<std::vector<float>*>();
                std::vector<float>* targets = new std::vector<float>();
            public:
                Mnist(const std::string& dataset_path);
                ~Mnist();
                const float get_target_by_index(int index);
                const std::vector<float>* get_digit_by_index(int index);
                void print_digit_to_console_by_index(int index);
        };

    };
    
};
