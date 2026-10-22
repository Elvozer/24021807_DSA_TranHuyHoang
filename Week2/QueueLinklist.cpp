class QueueLinkedList {
private:
    struct Node {
        int data;
        Node* next;
        Node(int val) : data(val), next(nullptr) {}
    };
    Node* head;
    Node* tail;
    int count;

public:
    QueueLinkedList() : head(nullptr), tail(nullptr), count(0) {}

    ~QueueLinkedList() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    // O(1) - Kiểm tra rỗng
    bool isEmpty() const {
        return head == nullptr;
    }

    // O(1) - Kích thước hàng đợi
    int size() const {
        return count;
    }

    // O(1) - Thêm vào cuối hàng đợi
    void enqueue(int item) {
        Node* newNode = new Node(item);
        if (isEmpty()) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        count++;
    }

    // O(1) - Xóa và lấy phần tử ở đầu hàng đợi
    int dequeue() {
        Node* temp = head;
        int val = temp->data;
        head = head->next;
        if (head == nullptr) {
            tail = nullptr;
        }
        delete temp;
        count--;
        return val;
    }

    // O(1) - Xem phần tử đầu hàng đợi
    int front() const {
        return head->data;
    }
};