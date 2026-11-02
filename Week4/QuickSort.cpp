#include <iostream>

using namespace std;

int partition(int A[], int l, int h) {
    int pivot = A[l];
    int i = l + 1, j = h;

    while (i <= j) {
        while (i <= h && A[i] <= pivot)  i++;
        while (A[j] > pivot)   j--;

        if (i < j) 
        swap(A[i], A[j]);
    }
    swap(A[l], A[j]);

    return j;
}

void QuickSort(int A[], int l, int h) {
    int j;
    if (l < h) {
        j = partition(A, l, h);
        QuickSort(A, l, j - 1);
        QuickSort(A, j + 1, h);
    }
}
