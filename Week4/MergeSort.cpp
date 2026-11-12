#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *next;
};

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

int findMax(int A[], int n) {
    int max = -1;
    for (int i = 0; i < n; i++) {
        if (A[i] > max)
            max = A[i];
    }
    return max;
}

void CountSort(int A[], int n) {
    int i, j, max, *C;

    max = findMax(A, n);

    C = new int [max + 1];

    for (int i = 0; i < max + 1; i++) {
        C[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        C[A[i]]++;
    }

    i = 0, j = 0;
    while (i <= max) {
        if (C[i] > 0) {
            A[j++] = i;
            C[i]--;
        } else {
            i++;
        } 
    }
}

void Insert(Node **head, int data) {
    Node *tmp = new Node {data, NULL};
    if (*head == NULL) {
        *head = tmp;
        return;
    }

    Node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = tmp;
}

int Delete(Node **head) {
   if (*head == NULL)   return -1;
    int data = (*head)->data;
   Node *temp = (*head)->next;
    delete *head;
    *head = temp;
    return data;
}

void RadixSort(int A[], int n) {
    Node **Bins;

    Bins = new Node *[10];

    for (int i = 0; i < 10; i++) {
        Bins[i] = NULL;
    }
    for (int j = 1; j <= 10; j = j * 10) {
        for (int i = 0; i < n; i++) {
            int index = (A[i] / j) % 10;
            Insert(&Bins[index], A[i]);
        }
        int i = 0, k = 0;
        while (i < 10) {
            if (Bins[i] != NULL) {
                A[k++] = Delete(&Bins[i]);
            } else {
                i++;
            }
        }
    }
}

int main() {
    int A[] = {1, 3, 7, 4, 8, 14, 11, 15};
    RadixSort(A, 8);

    for (int i = 0; i < 8; i++) {
        cout << A[i] << " ";
    }

    cout << endl;
}