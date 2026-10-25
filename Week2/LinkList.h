#include<iostream>

using namespace std;

struct Node {
    int data;
    Node *next;
};

class LinkList {
private:
    Node *head = NULL;

    void print_traverse_back(Node *node) {
        if (node == NULL)   return;
        print_traverse_back(node->next);
        cout << node->data << " ";
    }

public:

    ~LinkList() {
        while (head != NULL) {
            Node *temp = head->next;
            delete head;
            head = temp;
        }
    }

    int get_value(int index) {  // O(n)
        Node *temp = head;
        int i = 0;
        while (i != index) {
            temp = temp->next;
            i++;
        }

        return temp->data;
    }

    bool isEmpty() {
        return head == NULL;
    }

    Node *insert_head(int data) {    // O(1)
        Node *temp = new Node{data, NULL};
        temp->next = head;
        head = temp;
        return head;
    }

    Node *Append(int data) {    // O(n)
        Node *new_node = new Node{data, NULL};
        if (head == NULL) {
            head = new_node;
            return head;
        }
        Node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = new_node;

        return head;
    }  

    Node *insert(int data, int index) {     // O(n)
        if (index == 0) return insert_head(data);

        Node *new_nod = new Node {data, NULL};
        Node *temp = head;
        int i = 0;
        while (i != index - 1) {
            temp = temp->next;
            i++;
        }

        Node *temp_2 = temp->next;

        temp->next = new_nod;

        new_nod->next = temp_2;

        return head;
    }

    Node *remove_head(int &data) {   // O(1)
        Node *temp = head->next;
        data = head->data;
        delete head;
        head = temp;
        return head;
    }

    Node *remove_end(void) {    // O(n)
        if (head->next == NULL) {
            delete head;
            head = NULL;
            return head;
        }
        Node *temp = head;

        while (temp->next->next != NULL) {
            temp = temp->next;
        }    

        delete temp->next;
        temp->next = NULL;

        return head;
    }


    Node *remove(int index) {   // O(n)
        int data;
        if (index == 0) return remove_head(data);
        Node *temp = head;
        int i = 0;
        while (i != index - 1) {
            temp = temp->next;
            i++;
        }

        Node *temp_2 = temp->next->next;
        delete temp->next;
        temp->next = temp_2;
        return head;
    }

    int traverse(void) {   // O(n)
        int length {};
        Node *temp = head;
        while (temp != NULL) {
            length++;
            temp = temp->next;
        }
        return length;
    }

    void traverse_back() {
        print_traverse_back(head);
        cout << endl;
    }
};