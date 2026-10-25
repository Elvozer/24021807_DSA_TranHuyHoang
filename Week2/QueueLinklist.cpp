#include "LinkList.h"

class QueueLinkList {
private:
    LinkList queue_linklist;
    int length;
public:

    QueueLinkList() {
        length = 0;
    }

    bool isEmpty() {    // O(1)
        return length == 0;
    }

    void enqueue(int item) {    // O(n)
        queue_linklist.Append(item);
        length++;
    }

    int dequeue() {     // O(1)
        int data;
        queue_linklist.remove_head(data);
        length--;
        return data;
    }

    int front() {   // O(1)
        return queue_linklist.get_value(0);
    }

    int size() {    // O(1)
        return length;
    }
};