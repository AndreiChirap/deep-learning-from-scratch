#include <iostream>
#include <filesystem>
#include <string>

#include "../header/MNIST.h"

DeepLearning::MNIST::MNIST(const std::string& dataset_path){
    std::ifstream in(dataset_path);
    std::string contents((std::istreambuf_iterator<char>(in)), std::istreambuf_iterator<char>());
    std::vector<std::string> digits_tokens = MNIST::split(contents, "\n");
    for(auto& digit: digits_tokens){
        std::vector<std::string> pixels_tokens = MNIST::split(digit, ",");
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

DeepLearning::MNIST::~MNIST(){

}

float DeepLearning::MNIST::get_target_by_index(int index){
    return this->targets->at(index);
}
std::vector<float>* DeepLearning::MNIST::get_digit_by_index(int index){
    return this->digits->at(index);
}
void DeepLearning::MNIST::print_digit_to_console_by_index(int index){
    std::vector<float> digit = *this->get_digit_by_index(index);
    int counter = 0;
    for(auto pixel: digit){
        counter++;
        if(pixel < 10){
            std::cout<<pixel<<"  ";
        }else if( (pixel > 10) && (pixel < 100) ){
            std::cout<<pixel<<" ";
        }else{
            std::cout<<pixel;
        }
        if (counter % 28 == 0){
            std::cout << std::endl;
        }
    }
    std::cout<<std::endl;
    std::cout<< "Label: " << this->get_target_by_index(index) << std::endl;
    std::cout<<std::endl;
}

std::vector<std::string> DeepLearning::MNIST::split (const std::string& s, const std::string& delimiter){
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    std::string token;
    std::vector<std::string> res;
    while ((pos_end = s.find (delimiter, pos_start)) != std::string::npos) {
        token = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back (token);
    }
    res.push_back(s.substr (pos_start));
    return res;
}