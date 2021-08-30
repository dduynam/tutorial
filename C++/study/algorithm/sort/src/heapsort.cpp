#include "../lib/heapsort.h"

void displayHeapSort(std::vector<int> &_arr)
{
    std::cout << "HeapSortArray: ";
    for (int i = 0; i < _arr.size(); i++)
    {
        std::cout << _arr[i] << " ";
    }
    std::cout << std::endl;
}

void heapify(std::vector<int> &arr, int length, int i)
{
    int largest = i; //Initialize the largest as root.
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // If left child is greater then root
    if (left < length && arr[left] > arr[largest])
        largest = left;

    // If right child is greater than the current largest (means right child > left child)
    if (right < length && arr[right] > arr[largest])
        largest = right;

    // If largest is not root
    if (largest != i)
    {
        std::swap(arr[i], arr[largest]);

        // Recursively heapify the sub-tree that its root has been modified.
        heapify(arr, length, largest);
    }
}

void heapSort(std::vector<int> &arr, int n)
{
    // Build heap: Re-arrange array in bottom-up manner as max-heap principle
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }

    /*  After building max-heap --> root is largest and the last items of heap is smallest
        Perform to One by one swap the largest item stored at the parent to the last item

    */
    for (int i = n - 1; i > 0; i--)
    {
        // Move the current root value to the end
        std::swap(arr[0], arr[i]);

        // Proceed call heapify the heapified array after removing 1 element
        heapify(arr, i, 0);
    }
}