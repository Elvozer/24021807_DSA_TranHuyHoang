#include<iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    long long result = 1;
    for (int i = n; i > 1; i--) {
        result *= i;
    }

    cout << result << endl;
    return 0;
}

/*
 * ==========================================
 * PHÂN TÍCH ĐỘ PHỨC TẠP (BÀI 3 - TÍNH N!)
 * ==========================================
 * 1. Time Complexity:
 *    - Best case = Worst case = Average case: O(n)
      - Do thuật toán lặp tuần tự từ n về 2, luôn thực hiện chính xác (n - 1) phép nhân 
        với mọi giá trị n >= 2
 * 
 * 2. Space Complexity:
 *    - Best case = Worst case = Average case: O(1)
 *    - Do thuật toán xử lý tại chỗ, lượng bộ nhớ sử dụng hoàn toàn cố định
 *      và không bị biến động theo kịch bản dữ liệu đầu vào.
 * ==========================================
 */