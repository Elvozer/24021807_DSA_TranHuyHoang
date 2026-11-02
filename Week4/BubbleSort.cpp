#include <iostream>

using namespace std;

void BubbleSort(int A[], int size) {
    int flag;
    for (int i = 0; i < size - 1; i++) {
        flag = 0;
        for (int j = 0; j < size - i - 1; j++) {
            if (A[j] > A[j + 1]) {
                swap(A[j], A[j + 1]);
                flag = 1;
            }
        }
        
        if (flag == 0) break;   // adaptive
    }
}