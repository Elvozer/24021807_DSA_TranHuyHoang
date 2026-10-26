#include<iostream>

using namespace std;

struct Cell {
    int key;
    int data;
};
class List{
private:
    Cell *A;
    int length;
    int size;
public:

    List(int cap = 100) {
        size = cap;
        length = 0;
        A = new Cell[size];
        for (int i = 0; i < size; i++) {
            A[i] = {-1, -1};
        }
    }

    ~List() {
        delete []A;
    }
    
    int get_length() {
        return length;
    }

    int get_value(int index) {
        return A[index].data; //O(1)
    }

    int get_key(int index) {
        return A[index].key;
    }

    void set_cell(Cell new_cell, int index) {
        A[index] = new_cell;
        length++;
    }

    int remove_cell(int index) {
        int data = get_value(index);
        A[index] = {-2, -1};
        length--;
        return data;
    }

    void insert_head(int data) {   // O(n)
        int i;
        for (i = length; i > 0; i--) {
            A[i] = A[i - 1];
        }
        length++;
        A[0].data = data; 
    } 

    void insert_end(int data) {     // O(1)
        A[length].data = data;
        length++;
    }
    
    void Append(int data) {     // O(1)
        A[length].data = data;
        length++;
    } 

    void insert(Cell new_cell, int index) {  // O(n)
        int i;
        for (i = length; i > index; i--) {
            A[i] = A[i - 1];
        }

        A[i] = new_cell;
        length++;

    }

    int remove_head(void) {     // O(n)
        int head_data = A[0].data;
        for (int i = 0; i < length - 1; i++) {
            A[i] = A[i + 1];
        }

        length--;
        return head_data;
    }

    int remove_end(void) {
        int end_data = A[length - 1].data;   // O(1)
        length--;
        return end_data;
    }

    int remove(int index) {
        int remove_data = A[index].data;     // O(n)
        for (int i = index; i < length - 1; i++) {
            A[i] = A[i + 1];
        }
        length--;
        return remove_data;
    }

    bool search(int key) {     // O(n)
        for (int i = 0; i < length; i++) {      
            if (A[i].key == key) return true;
        }

        return false;
    }

    void go_backward(void) {    // O(n)
        for (int i = length - 1; i >= 0; i--) {
            cout << A[i].data << " ";
        }

        cout << endl;
    }
};