#include "LinkList.h"
#include <iostream>

using namespace std;

class StackLinkList {
private:
    LinkList stack_linklist;
    int length;
public:

    StackLinkList() {
        length = 0;
    }

    bool isEmpty() {    // O(1)
        return length == 0;
    }

    void push(int item) {   // O(1)
        stack_linklist.insert_head(item);
        length++;
    }

    int pop() {     // O(1)
        int data;
        stack_linklist.remove_head(data);
        length--;
        return data;
    }

    int size() {    // O(1)
        return length;
    }

    int top() {     // O(1)
        return stack_linklist.get_value(0);
    }

};