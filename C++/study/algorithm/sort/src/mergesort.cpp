#include "../lib/mergesort.h"

void displayMergeSort(std::vector<int> &_arr)
{
    std::cout << "MergeSortArray: ";
    for (int i = 0; i < _arr.size(); i++)
    {
        std::cout << _arr[i] << " ";
    }
    std::cout << std::endl;
}

/*-----------Merge Function--------
Mechanism: merge(arr,l,m,r) assumes that two arrays 
arr[l..m] and arr[m+1..r] we need to merge already are sorted. 
*/
void merge(std::vector<int> &arr, int left, int mid, int right)
{
    auto const LeftArraySize = mid - left + 1;
    auto const RightArraySize = right - mid;

    // Create temp arrays
    std::vector<int> LeftArray(LeftArraySize, 0);
    std::vector<int> RightArray(RightArraySize, 0);

    // Devide the arr into 2 halves
    for (int i = 0; i < LeftArraySize; i++)
    {
        LeftArray[i] = arr[left + i];
    }
    for (int i = 0; i < RightArraySize; i++)
    {
        RightArray[i] = arr[mid + 1 + i];
    }

    // Initialize index of array
    int indexOfLeftArray = 0;
    int indexOfRightArray = 0;
    int indexOfMergedArray = left; // Sort and merge right on the original array.

    // Compare --> sort --> merge into the arr[left..right]
    while (indexOfLeftArray < LeftArraySize && indexOfRightArray < RightArraySize)
    {
        if (LeftArray[indexOfLeftArray] <= RightArray[indexOfRightArray])
        {
            arr[indexOfMergedArray] = LeftArray[indexOfLeftArray];
            indexOfLeftArray++;
        }
        else
        {
            arr[indexOfMergedArray] = RightArray[indexOfRightArray];
            indexOfRightArray++;
        }
        indexOfMergedArray++;
    }

    // Handle remaining element of LeftArray
    while (indexOfLeftArray < LeftArraySize)
    {
        arr[indexOfMergedArray] = LeftArray[indexOfLeftArray];
        indexOfMergedArray++;
        indexOfLeftArray++;
    }

    // Handle remaining element of RightArray
    while (indexOfRightArray < RightArraySize)
    {
        arr[indexOfMergedArray] = RightArray[indexOfRightArray];
        indexOfRightArray++;
        indexOfMergedArray++;
    }
}

/*-----------Merge Sort---------------
Method: 
    1. Find the middle point to devide input array into two halves
    2. Call itself for the two halves
    3. When the subarray just has only 2 elements. Devide it into 2 halves. Each half contains 1 element. 
    4. Proceed to sort and merge each two-half until we get the complete array.
*/
void mergeSort(std::vector<int> &arr, int left, int right)
{
    if (left >= right)
        return;

    int mid = left + (right - left)/2; 
    mergeSort(arr, left, mid);
    mergeSort(arr, mid+1, right);
    merge(arr, left, mid, right);
}
