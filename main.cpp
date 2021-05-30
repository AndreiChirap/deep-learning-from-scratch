#include "./header/datasets.h"
#include "./header/utils.h"

using namespace deep_learning;

int main(){
    //load dataset to memory
    utils::print("Loading training set...");
    datasets::Mnist* train_dataset = new datasets::Mnist("./dataset/train.txt");
    
    utils::print("Loading test set...");
    datasets::Mnist* test_dataset = new datasets::Mnist("./dataset/test.txt");

    //print some digits, for debugging purpose
    train_dataset->print_digit_to_console_by_index(0);
    test_dataset->print_digit_to_console_by_index(0);

    //don't forget to free the memory
    delete train_dataset;
    delete test_dataset;
    return 0;
}