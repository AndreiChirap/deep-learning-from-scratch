#pragma once
#include <string>
#include <vector>

namespace DeepLearning{
    class MNIST{
        private:
            std::vector<std::vector<float>*>* digits = new std::vector<std::vector<float>*>();
            std::vector<float>* targets = new std::vector<float>();
        public:
            MNIST(const std::string& dataset_path);
            ~MNIST();
            float get_target_by_index(int index);
            std::vector<float>* get_digit_by_index(int index);
            void print_digit_to_console_by_index(int index);
        private:
            static std::vector<std::string> split (const std::string& s, const std::string& delimiter);
    };
}
