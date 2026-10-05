#include<iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    double arr[10000];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    double average {};
    for (int i = 0; i < n; i++) {
        average += arr[i];
    }

    average /= n;
    for (int i = 0; i < n; i++) {
        if (arr[i] >= average) cout << arr[i] << " ";
    }

    return 0;
}

/* Phân tích thuật toán (Bài 5)
Time Complexity:
    - Best case = Worst case = Average case = O(n):
    - Vì thuật toán luôn phải duyệt qua đủ n phần tử trong 3 vòng lặp tuần tự 
      (nhập mảng, tính tổng, so sánh in kết quả).

Space Complexity:
    - Bộ nhớ phụ trợ O(1): do chỉ sử dụng thêm các biến phụ đơn lẻ.
    - Tổng bộ nhớ O(n): do cần lưu trữ n phần tử của dãy số để phục vụ cho việc tính trung bình và duyệt lại so sánh.
*/