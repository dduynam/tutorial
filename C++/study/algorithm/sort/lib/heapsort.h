#ifndef _HEAPSORT_H_
#define _HEAPSORT_H_
#include <bits/stdc++.h>

void displayHeapSort(std::vector<int> &_arr);

/*
Description: Heapify the a subtree rooted with node i, of an array 'arr' with size is n 
*/
void heapify(std::vector<int> &arr, int length, int i);

/*-----------Heap Sort--------------
Mechanism: <sorting in increasing order> 
    1. Build a max heap from the input data 
    2. After build the largest item stored at the root of the heap. 
    Replace it with the last item followed by reducing the size of heap by 1. 
    3. Repeat step 2 until the size of the heap is smaller than 1. 
    
    Last parent node: n/2 - 1
*/
void heapSort(std::vector<int> &arr, int n);

#endif