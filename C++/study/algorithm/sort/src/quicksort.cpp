#include "../lib/quicksort.h"

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

/* The partition function
    1. Take the last element as pivot
    2. Place the pivot to the correct position by comparing
    3. Move the smaller value to the left
    4. Move the greater value to the right 
Note: low --> starting index ; high --> ending index ; return the pivot index 
*/
int partition(std::vector<int> &_arr, int low, int high)
{
    int pivot = _arr[high];
    int i = low - 1; // idex of the smaller element

    for (int j = low; j < high; j++)
    {
        if (_arr[j] <= pivot)
        {
            i++;
            swap(_arr[i], _arr[j]);
        }
    }

    swap(_arr[i + 1], _arr[high]);
    return (i + 1);
}

void displayQuickSort(std::vector<int> &_arr)
{
    std::cout << "QuickSortArray: ";
    for (int i = 0; i < _arr.size(); i++)
    {
        std::cout << _arr[i] << " ";
    }
    std::cout << std::endl;
}

void quickSort(std::vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);

    }
}

// 4 8 7 3 5 0 3 4
// 4 3 0 3 4 7 8 5