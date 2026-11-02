#include <iostream>

using namespace std;

void insertionSort(int A[], int n) {
    for (int i = 1; i < n; i++) {
        int j = i - 1;
        int temp = A[i];
        while (j > -1 && A[j] > temp) {
            A[j + 1] = A[j];
            j--;
        }

        A[j + 1] = temp;
    }
}
