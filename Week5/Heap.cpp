#include <iostream>
#include <utility> 

using namespace std;

class MaxHeap {
private:
    int *A;
    int size;
    int capacity;

    void insert(int val) {
        if (size >= capacity) return;
        size++;
        int i = size;

        while (i > 1 && val > A[i / 2]) {
            A[i] = A[i / 2];
            i = i / 2;
        }
        A[i] = val;
    }

    int deleteMax() {
        int maxVal = A[1];
        A[1] = A[size];
        size--;

        int i = 1;
        int j = 2 * i; 

        while (j <= size) {
            if (j + 1 <= size && A[j + 1] > A[j]) {
                j = j + 1;
            }
            if (A[j] > A[i]) {
                swap(A[i], A[j]);
                i = j;
                j = 2 * i;
            } else {
                break;
            }
        }
        return maxVal;
    }

public:
    MaxHeap() {
        A = nullptr;
        size = 0;
        capacity = 0;
    }

    ~MaxHeap() {
        delete[] A;
    }

    void create(int Arr[], int n) {
        delete[] A; 
        capacity = n;
        size = 0;
        A = new int[n + 1];

        for (int i = 0; i < n; i++) {
            insert(Arr[i]);
        }
    }

    void heapSort() {
        int originalSize = size;
        while (size > 1) {
            int maxVal = deleteMax();
            A[size + 1] = maxVal;
        }
        size = originalSize;
    }
};
