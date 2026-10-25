#include "List.h"

class QueueList {
private:   
    List queue_list;
public: 
    bool isEmpty() {    // O(1)
        return queue_list.get_length() == 0;
    }

    void enqueue(int item) {    // O(1)
        queue_list.insert_end(item);
    }

    int dequeue() {     // O(n)
        return queue_list.remove_head();
    }

    int front() {   // O(1)
        return queue_list.get_value(0);
    }

    int size() {    // O(1)
        return queue_list.get_length();
    }
};