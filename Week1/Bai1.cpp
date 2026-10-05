#include<iostream>

using namespace std;

int main() {
    int n {}, sum {};   
    cin >> n;   
    int arr[10000];  
    for (int i = 0; i < n; i++) {   
        cin >> arr[i];  
        sum += arr[i];  
    } 
    cout << sum;
    return 0;
}

/*
 * PHÂN TÍCH ĐỘ PHỨC TẠP:
 * 1. Time Complexity:
 *    - Best case: O(n) =  Worst case: O(n) = Average case: O(n) 
 *    - Do với mọi kiểu dữ liệu đầu vào thì vòng for() vẫn phải duyệt hết mảng
 * 
 * 2. Memory Complexity:
 *    - Bộ nhớ phụ trợ O(1): do chỉ dùng thêm biến n, sum, i.
      - Tổng bộ nhớ O(n) do chương trình đang lưu trữ lại toàn bộ n phần tử vào mảng arr.
 */