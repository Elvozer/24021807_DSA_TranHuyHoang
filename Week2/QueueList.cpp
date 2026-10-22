class QueueList {
private:
    int* arr;
    int capacity;
    int frontIdx;
    int rearIdx;
    int count;

    void resize() {
        int newCapacity = capacity * 2;
        int* newArr = new int[newCapacity];
        // Sao chép lại các phần tử theo đúng thứ tự từ frontIdx
        for (int i = 0; i < count; i++) {
            newArr[i] = arr[(frontIdx + i) % capacity];
        }
        delete[] arr;
        arr = newArr;
        frontIdx = 0;
        rearIdx = count;
        capacity = newCapacity;
    }

public:
    QueueList(int initCap = 4) 
        : capacity(initCap), frontIdx(0), rearIdx(0), count(0) {
        arr = new int[capacity];
    }

    ~QueueList() {
        delete[] arr;
    }

    // O(1) - Kiểm tra rỗng
    bool isEmpty() const {
        return count == 0;
    }

    // O(1) - Kích thước queue
    int size() const {
        return count;
    }

    // O(1) trung bình (Amortized) - Thêm phần tử vào đuôi
    void enqueue(int item) {
        if (count == capacity) {
            resize();
        }
        arr[rearIdx] = item;
        rearIdx = (rearIdx + 1) % capacity;
        count++;
    }

    // O(1) - Xóa và trả về phần tử ở đầu
    int dequeue() {
        int val = arr[frontIdx];
        frontIdx = (frontIdx + 1) % capacity;
        count--;
        return val;
    }

    // O(1) - Xem phần tử ở đầu
    int front() const {
        return arr[frontIdx];
    }
};