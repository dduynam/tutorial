#include "../lib/insertionsort.h"

void displayInsertionSort(std::vector<int> &_arr)
{
    std::cout << "InsertionSortArray: ";
    for (int i = 0; i < _arr.size(); i++)
    {
        std::cout << _arr[i] << " ";
    }
    std::cout << std::endl;
}

/*  Insertion Sort
    Key: starts from the 2nd element of the array. Left of key is sorted array, right of its is unsorted.
    Mechanism: 
        1. Compare the key to the biggest value of the sorted part (left side). 
        2. Move the key to the correct position in the sorted array.
        3. For each greater value than key, shift this value to right 1 unit and continue to compare key
        with the others in sorted array.
        4. When the condition is wrong, swap the key with the current index.   
*/
void insertionSort(std::vector<int> &arr)
{
    int size = arr.size();
    int key, i, j;
    for (i = 1; i < size; i++)
    {
        key = arr[i]; // Key starts from the 2nd element of the array
        j = i - 1;

        /* move the elements of arr[0..i -1], that are greater than key, to one position ahead 
        of their current position */
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// 4 8 7 3 5 0 3 4
// 4 3 0 3 4 7 8 5

/* --------------- binary-Insertion-Search ---------------- 
Purpose: Find a position where the item should be inserted in arr[low..high]
Prerequisite: the array should be sorted in advance. 
*/
int binarySearch(std::vector<int> &arr, int item, int low, int high)
{
    if (high < low)
        return (item > arr[low]) ? (low + 1) : low;
    
    int mid = (low+high)/2;

    if (item == arr[mid])
        return mid + 1;
    
    if (item > arr[mid])
        return binarySearch(arr, item, mid+1, high);
    
    return binarySearch(arr, item, low, mid-1);
}

/*  Binary-Insertion-Sort
    Reason: apply binary search will help us find the correct position of "key" value in the sorted array
    faster --> Complexity: 0(nlog(n)) */ 
void binaryInsertionSort(std::vector<int> &arr)
{
    int size = arr.size();
    int key, i, j, loc;

    for (i = 1; i < size; i++)
    {
        key = arr[i];
        j = i - 1;

        /* Find the position where the key should be inserted */
        loc = binarySearch(arr, key, 0, j);

        while (j >= loc)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1]= key;
    }
    
}