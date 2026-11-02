#include <iostream>

using namespace std;

void SelectionSort(int A[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int j = i + 1, k = i;
        while (j < n) {
            if (A[j] < A[k]) k = j;
            j++;
        }

        swap(A[i], A[k]);
    }
}
