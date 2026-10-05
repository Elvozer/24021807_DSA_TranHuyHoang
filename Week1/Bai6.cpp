#include<iostream>

using namespace std;

void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void removeEle(int arr[], int &n) {
    int k;
    cout << "Nhap vi tri phan tu can xoa: ";
    cin >> k;
    for (int i = k - 1; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--;
}

void insert(int arr[], int &n) {
    int m, y;
    cout << "Nhap lan luot gia tri phan tu can chen va vi tri chen: ";
    cin >> y >> m;
    for (int i = n; i >= m; i--) {
        arr[i] = arr[i - 1];
    }

    arr[m - 1] = y;
    n++;
}

int main() {
    int n;
    cin >> n;
    int arr[10000];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    print_array(arr, n); // Trước khi thay đổi mảng

    removeEle(arr, n);

    print_array(arr, n);   // Sau khi xoá một phần tử ở vị trí k

    insert(arr, n);

    print_array(arr, n);  // Sau khi chèn thêm một phần tử ở vị trí m

    return 0;
}

/* Phân tích thuật toán (Bài 6)
Time Complexity:
    - Best case O(1): do việc chèn hoặc xoá ở cuối mảng sẽ được thực hiện mà ko cần phải chạy vòng lặp for().
    - Worst case O(n): do việc chèn hoặc xoá ở đầu mảng sẽ yêu cầu việc dịch chuyển lại vị trí của tất cả phần tử bằng vòng for().
    - Average case O(n): giả sử việc chèn hoặc xoá diễn ra ở giữa mảng, vậy thì vẫn phải cần n/2 lần sắp xếp các phần tử ở sau đó.
Space Complexity:
    - Bộ nhớ phụ trợ O(1): do chỉ sử dụng thêm các biến đơn lẻ.
    - Tổng bộ nhớ O(n): do cần lưu trữ n phần tử của dãy số để phục vụ cho việc chèn hoặc xoá.
*/