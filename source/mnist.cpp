#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>

#include "../header/utils.h"
#include "../header/datasets.h"

deep_learning::datasets::Mnist::Mnist(const std::string& dataset_path){
    std::ifstream in(dataset_path);
    std::string contents((std::istreambuf_iterator<char>(in)), std::istreambuf_iterator<char>());
    std::vector<std::string> digits_tokens = deep_learning::utils::split(contents, "\n");
    for(auto& digit: digits_tokens){
        std::vector<std::string> pixels_tokens = deep_learning::utils::split(digit, " ");
        std::vector<float>* float_digit = new std::vector<float>();
        int i = 0;
        for(auto& pixel: pixels_tokens){
            float pixel_value = std::stof(pixel);
            if (i < (pixels_tokens.size() - 1)){
                float_digit->push_back(pixel_value);
                i++;
            }else{
                this->targets->push_back(pixel_value);
            }
        }
        this->digits->push_back(float_digit);
    }        
}

deep_learning::datasets::Mnist::~Mnist(){
    for(auto& digit: *this->digits){
        digit->clear();
    }
    delete this->digits;
    this->targets->clear();
    delete this->targets;
}

const float deep_learning::datasets::Mnist::get_target_by_index(int index){
    return this->targets->at(index);
}
const std::vector<float>* deep_learning::datasets::Mnist::get_digit_by_index(int index){
    return this->digits->at(index);
}
void deep_learning::datasets::Mnist::print_digit_to_console_by_index(int index){
    std::vector<float> digit = *this->get_digit_by_index(index);
    int counter = 0;
    for(auto pixel: digit){
        counter++;
        if(pixel < 10){
            std::cout << pixel<<"  ";
        }else if( (pixel >= 10) && (pixel < 100) ){
            std::cout << pixel<<" ";
        }else{
            std::cout << pixel;
        }
        if (counter % 28 == 0){
            std::cout << std::endl;
        }
    }
    std::cout << std::endl;
    std::cout << "Label: " << this->get_target_by_index(index) << std::endl;
    std::cout << std::endl;
}