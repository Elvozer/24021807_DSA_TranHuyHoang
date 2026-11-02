#include <iostream>

using namespace std;

int *Merge(int A[], int B[], int m, int n) {
    int *result = new int [m + n];

    int i = 0, j = 0, k = 0;
    while (i < m && j < n) {
        if (A[i] < B[j]) {
            result[k++] = A[i++];
        } else {
            result[k++] = B[j++];
        }
    }

    while (i < m) {
        result[k++] = A[i++];
    }

    while (j < n) {
        result[k++] = B[j++];
    }

    return result;
}

void SMerge(int A[], int l, int mid, int high) {
    int i = l, j = mid + 1;
    int k = l;
    int B[100];
    while (i <= mid && j <= high) { 
        if (A[i] <= A[j]) 
            B[k++] = A[i++];
        else 
            B[k++] = A[j++]; 
    }

    while (i <= mid) 
        B[k++] = A[i++];
    while (j <= high)
        B[k++] = A[j++];
    
    for (int a = l; a <= high; a++) 
        A[a] = B[a];
}

void IterativeMergeSort(int A[], int n) {
    int p, l, h, mid, i;

    for (p = 2; p <= n; p = p*2) {

        for (i = 0; i + p - 1 < n; i = i + p) {
            l = i;
            h = i + p - 1;
            mid = ( l + h ) / 2;
            SMerge(A, l, mid, h);
        }
    }

    if (p/2 < n)
        SMerge(A, 0, p/2 - 1, n - 1);
}

void RMergeSort(int A[], int l, int h) {
    if (l < h) {
        int mid = (l + h) / 2;
        RMergeSort(A, l, mid);
        RMergeSort(A, mid + 1, h);
        SMerge(A, l, mid, h);
    }
}
