#include <bits/stdc++.h>
#include "lib/bubblesort.h"
#include "lib/quicksort.h"
#include "lib/insertionsort.h"
#include "lib/mergesort.h"

int main()
{

    std::vector<int> arr{1, 3, 6, 2, 4, 5, 8, 7};
    //BubbleSort(arr);
    //displayBubbleSort(arr);

    std::vector<int> quickarray{4, 8, 7, 3, 5, 0, 3, 4};
    int size = quickarray.size();
    quickSort(quickarray, 0, size - 1);
    std::cout << "After quicksorting." << std::endl;
    displayQuickSort(quickarray);

    std::cout << "\n-------------\n";
    std::cout << "Insertion Sort\n";
    std::vector<int> insertionarray{4, 8, 7, 3, 5, 0, 3, 4};
    binaryInsertionSort(insertionarray);
    std::cout << "After insertionsorting." << std::endl;
    displayInsertionSort(insertionarray);

    std::cout << "\n-------------\n";
    std::cout << "Merge Sort\n";
    std::vector<int> mergearray{4, 8, 7, 3, 5, 0, 3, 4};
    mergeSort(mergearray, 0, mergearray.size()-1);
    std::cout << "After mergesorting." << std::endl;
    displayMergeSort(mergearray);

    return 0;
}