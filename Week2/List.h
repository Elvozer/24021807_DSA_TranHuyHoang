#include<iostream>

using namespace std;

class List{
private:
    int *A;
    int length;
    int size;
public:

    List(int cap = 100) {
        size = cap;
        length = 0;
        A = new int[size];
    }

    ~List() {
        delete []A;
    }
    
    int get_value(int index) {
        return A[index]; //O(1)
    }

    int get_length() {
        return length;
    }

    void insert_head(int data) {   // O(n)
        int i;
        for (i = length; i > 0; i--) {
            A[i] = A[i - 1];
        }
        length++;
        A[0] = data; 
    } 

    void insert_end(int data) {     // O(1)
        A[length] = data;
        length++;
    }
    
    void Append(int data) {     // O(1)
        A[length] = data;
        length++;
    } 

    void insert(int data, int index) {  // O(n)
        int i;
        for (i = length; i > index; i--) {
            A[i] = A[i - 1];
        }

        A[i] = data;
        length++;

    }

    int remove_head(void) {     // O(n)
        int head_data = A[0];
        for (int i = 0; i < length - 1; i++) {
            A[i] = A[i + 1];
        }

        length--;
        return head_data;
    }

    int remove_end(void) {
        int end_data = A[length - 1];   // O(1)
        length--;
        return end_data;
    }

    int remove(int index) {
        int remove_data = A[index];     // O(n)
        for (int i = index; i < length - 1; i++) {
            A[i] = A[i + 1];
        }
        length--;
        return remove_data;
    }

    void go_forward(void) {     // O(n)
        for (int i = 0; i < length; i++) {      
            cout << A[i] << " ";
        }

        cout << endl;
    }

    void go_backward(void) {    // O(n)
        for (int i = length - 1; i >= 0; i--) {
            cout << A[i] << " ";
        }

        cout << endl;
    }
};