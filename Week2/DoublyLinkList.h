#include<iostream>

using namespace std;

struct Node {
    int data;
    Node *next;
    Node *prev;
};

class DoublyLinkList {
private:
    Node *head = NULL;
    Node *tail = NULL;
public:
    int get_value(int index) {      // O(n))
        Node *temp = head;
        int i = 0;
        while (i != index) {
            i++;
            temp = temp->next;
        }

        return temp->data;
    }

    int get_number_of_ele() {
        int i = 0;
        Node *temp = head;
        while (temp != NULL) {
            i++;
            temp = temp->next;
        }

        return i;
    }

    Node *insert_head(int data) {      // O(1)
        Node *new_node = new Node {data, NULL, NULL};
        if (head == NULL) {
            head = new_node;
            tail = new_node;
            return head;
        }
        Node *temp = head;
        head = new_node;
        head->next = temp;
        temp->prev = head;
        return head;
    }

    Node *insert_tail(int data) {       // O(1)
        Node *new_node = new Node {data, NULL, NULL};
        if (tail == NULL) {
            head = new_node;
            tail = new_node;
            return tail;   
        }
        Node *temp = tail;
        tail = new_node;
        tail->prev = temp;
        temp->next = tail;
        return tail;
    }

    Node *insert(int data, int index) {     // O(n)
        if (index == 0) return insert_head(data);
        else if (index == get_number_of_ele()) return insert_tail(data);
        Node *new_node = new Node {data, NULL, NULL};
        Node *temp = head;
        int i = 0;
        while (i != index - 1) {
            i++;
            temp = temp->next;
        }

        Node *temp_2 = temp->next;
        temp->next = new_node;
        new_node->prev = temp;
        new_node->next = temp_2;
        temp_2->prev = new_node;
        return head;
    }

    Node *remove_head() {   // O(1)
        Node *temp = head->next;
        delete head;
        head = temp;
        if (head == NULL) {
            tail = NULL;
            return head;
        }
        head->prev = NULL;
        return head;
    }

    Node *remove_tail() {   // O(1)
        Node *temp = tail->prev;
        delete tail;
        tail = temp;
        if (tail == NULL) {
            head = NULL;
            return head;
        }
        tail->next = NULL;
        return head;
    }

    Node *remove(int index) {   // O(n)
        if (index == 0) return remove_head();
        else if (index == get_number_of_ele() - 1) return remove_tail();

        Node *temp = head;
        int i = 0;
        while (i != index) {
            i++;
            temp = temp->next;
        }

        Node *prev = temp->prev;
        Node *next = temp->next;
        delete temp;
        prev->next = next;
        next->prev = prev;

        return head;
    }

    void traverse() {   // O(n)
        Node *temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void traverse_back() {  // O(n)
        Node *temp = tail;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << endl;
    }
};