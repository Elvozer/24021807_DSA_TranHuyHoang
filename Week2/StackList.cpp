#include "List.h"
#include <iostream>

class StackList {
private:
    List stack_data;
public:
    bool isEmpty() {
        return stack_data.get_length() == 0;
    }

    void push(int item) {   // O(1)
        stack_data.Append(item);
    }

    int pop() {     // O(1)
        return stack_data.remove_end();
    }

    int size() {    // O(1)
        return stack_data.get_length();
    }

    int top() {     // O(1)
        return stack_data.get_value(stack_data.get_length() - 1);
    }

};