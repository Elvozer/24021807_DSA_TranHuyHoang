#include <iostream>

using namespace std;

struct Array
{
    int A[10];
    int size;
    int length;
};

void Display(struct Array arr) {
    cout << "All elements are: ";
    for (int i = 0; i < arr.length; i++) {
        cout << arr.A[i] << " ";
    }
    cout << endl;
}

void Append(struct Array *arr, int x) {
    if (arr->length < arr->size) {
        arr->A[arr->length++] = x;
    }
}

void Insert(struct Array &arr, int index, int x) {
    if (index >= 0 && index <= arr.length) {
        for (int i = arr.length; i > index; i--) {
            arr.A[i] = arr.A[i - 1];
        }
        arr.A[index] = x;
        arr.length++;
    }
}

int LinearSearch(struct Array &arr, int key) {
    for (int i = 0; i < arr.length; i++) {
        if (key == arr.A[i]) {
            if (i != 0)
                swap(arr.A[i], arr.A[0]);
            return i;
        }
    }

    return -1;
}

int BinarySearch(struct Array arr, int key, int l, int h) {
    while (l <= h) {
        int mid = (l + h) / 2;
        if (key == arr.A[mid])
            return mid;
        else if (key < arr.A[mid]) 
            h = mid - 1;
        else 
            l = mid + 1;
    }

    return -1;
}

int RBinarySearch(struct Array arr, int key, int l, int h) {
    if (l > h)
        return -1;
    int mid = (l + h) / 2;
    if (key == arr.A[mid])
        return mid;
    else if (key < arr.A[mid])
        return RBinarySearch(arr, key, l, mid - 1);
    else
        return RBinarySearch(arr, key, mid + 1, h);
}

void swap(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}

int Delete(struct Array &arr, int index) {
    int x = 0;
    if (index < arr.size) {
        x = arr.A[index];
        for (int i = index; i < arr.length - 1; i++) 
            arr.A[i] = arr.A[i + 1];
            arr.length--;
    }
    return x;
}

int main() {
    struct Array arr = {{2, 3, 4, 5, 6}, 10, 5};
    cout << RBinarySearch(arr, 5, 0, 5);

    Display(arr);
    return 0;
}