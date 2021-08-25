#include <bits/stdc++.h>
#include "lib/bubblesort.h"
#include "lib/quicksort.h"

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

    return 0;
}