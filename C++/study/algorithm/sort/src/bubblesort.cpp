#include "../lib/bubblesort.h"

void BubbleSort(std::vector<int> &_arr){
    for (int i = 0; i < _arr.size()-1; i++)
    {
        for (int j = i+1; j < _arr.size(); j++)
        {
            if (_arr[i]>_arr[j])
                std::swap(_arr[i],_arr[j]);
        }  
    }
    
}

void displayBubbleSort(std::vector<int> &_arr){
    std::cout << "BublleSortArray: ";
    for (int i = 0; i < _arr.size(); i++)
    {
        std::cout << _arr[i] << " "; 
    }
    std::cout << std::endl;
}