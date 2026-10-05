#include<iostream>

using namespace std;

void sort_upward(int Arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (Arr[i] > Arr[j]) {
                int temp = Arr[i];
                Arr[i] = Arr[j];
                Arr[j] = temp;
            }
        }
    }
}

int main() {
    int n {}, arr[1000];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort_upward(arr, n);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }  

    return 0;
}

/*
 * ==========================================
 * PHÂN TÍCH ĐỘ PHỨC TẠP (BÀI 2 - SẮP XẾP)
 * ==========================================
 * 1. Time Complexity:
 *    - Số lần so sánh: Luôn cố định là (n - 1) + (n - 2) + ... + 1 = n*(n - 1)/2.
 *    - Best case:    O(n^2) - Mảng đã có thứ tự tăng dần (không tốn phép swap nhưng vẫn phải duyệt hết vòng lặp).
 *    - Worst case:   O(n^2) - Mảng bị xếp giảm dần (vừa duyệt hết vòng lặp vừa phải swap liên tục).
 *    - Average case: O(n^2) - Vẫn phải duyệt hết và so sánh từng phần tử
 *    -> Kết luận: Thuật toán không có điều kiện dừng sớm nên Time Complexity luôn là O(n^2) trong mọi trường hợp.
 * 
 * 
 * 2. Space Complexity:
   - Bộ nhớ phụ trợ O(1): vì thuật toán sắp xếp tại chỗ, chỉ sử dụng thêm các biến đơn 
        lẻ (i, j, temp) để hoán đổi.
   - Tổng cần O(n) không gian lưu trữ để chứa n phần tử của dãy số ban đầu.
*/