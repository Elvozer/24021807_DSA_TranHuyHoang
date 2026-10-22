class StackList {
private:
    int* arr;
    int capacity;
    int topIndex;

    void resize() {
        capacity *= 2;
        int* newArr = new int[capacity];
        for (int i = 0; i <= topIndex; i++) {
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
    }

public:
    StackList(int initCap = 4) : capacity(initCap), topIndex(-1) {
        arr = new int[capacity];
    }

    ~StackList() {
        delete[] arr;
    }

    // O(1) - Kiểm tra rỗng
    bool isEmpty() const {
        return topIndex == -1;
    }

    // O(1) - Kích thước stack
    int size() const {
        return topIndex + 1;
    }

    // O(1) trung bình (Amortized) - Thêm phần tử vào đỉnh
    void push(int data) {
        if (topIndex == capacity - 1) {
            resize();
        }
        arr[++topIndex] = data;
    }

    // O(1) - Xóa và trả về phần tử đỉnh
    int pop() {
        return arr[topIndex--];
    }

    // O(1) - Xem giá trị đỉnh
    int top() const {
        return arr[topIndex];
    }
};