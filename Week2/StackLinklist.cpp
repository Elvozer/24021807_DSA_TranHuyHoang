#include <iostream>
#include <stdexcept>

class StackLinkedList {
private:
    struct Node {
        int data;
        Node* next;
        Node(int val) : data(val), next(nullptr) {}
    };
    Node* head;
    int count;

public:
    StackLinkedList() : head(nullptr), count(0) {}

    ~StackLinkedList() {
        while (!isEmpty()) {
            pop();
        }
    }

    // O(1) - Kiểm tra rỗng
    bool isEmpty() const {
        return head == nullptr;
    }

    // O(1) - Kích thước stack
    int size() const {
        return count;
    }

    // O(1) - Thêm phần tử vào đỉnh
    void push(int data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
        count++;
    }

    // O(1) - Xóa và trả về phần tử đỉnh
    int pop() {
        Node* temp = head;
        int val = temp->data;
        head = head->next;
        delete temp;
        count--;
        return val;
    }

    // O(1) - Xem giá trị đỉnh
    int top() const {
        return head->data;
    }
};