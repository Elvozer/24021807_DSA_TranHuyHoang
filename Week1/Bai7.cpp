#include<iostream>

using namespace std;

void print_arr(int arr[][100], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int sumArr(int arr[][100], int &m, int &n) {
    int sum = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            sum += arr[i][j];
        }
    }

    return sum;
}

void remove_row(int arr[][100], int &m, int &n) {
    int i;
    cout << "Nhap hang can xoa: ";
    cin >> i;
    for (int row = i - 1; row < m - 1; row++) {
        for (int col = 0; col < n; col++) {
            arr[row][col] = arr[row + 1][col];
        }
    }

    m--;
}

int main() {
    int m, n;
    cin >> m >> n;
    int arr[100][100];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    cout <<"Tong la: " << sumArr(arr, m, n) << endl;

    print_arr(arr, m, n);   // Ma trận trước khi xoá hàng

    remove_row(arr, m, n);

    print_arr(arr, m, n);   // Ma trận sau khi xoá hàng
}

/* Phân tích thuật toán (Bài 7)
Time Complexity:
    - Câu a:
        + Do để tính tổng các phần tử trong mảng nên phải quét qua hết m*n các phần tử => Bestcase = Worstcase = Average case = O(m*n)
    - Câu b:
        + Best case O(1): khi mà thực hiện việc xoá hàng cuối của ma trận, vòng lặp không cần chạy để dịch chuyển phần tử nào.
        + Worst case O(m*n): khi thực hiện xoá hàng đầu tiên của ma trận, phải dịch chuyển m - 1 hàng, mỗi hàng có n phần tử.
        + Average case O(m*n): thực hiện việc xoá hàng bất kì ở giữa ma trận trung bình vẫn dịch chuyển m/2 * n phần tử.
Space Complexity:
    - Bộ nhớ phụ trợ O(1): do chỉ sử dụng thêm các biến đơn lẻ.
    - Tổng bộ nhớ O(m*n): do cần lưu trữ m*n phần tử của ma trận.
*/