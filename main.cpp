#include "./header/MNIST.h"

int main(){

    DeepLearning::MNIST* train_dataset = new DeepLearning::MNIST("./dataset/train.txt");
    DeepLearning::MNIST* test_dataset = new DeepLearning::MNIST("./dataset/test.txt");

    train_dataset->print_digit_to_console_by_index(0);
    test_dataset->print_digit_to_console_by_index(0);
    
    delete train_dataset;
    delete test_dataset;
    return 0;
}