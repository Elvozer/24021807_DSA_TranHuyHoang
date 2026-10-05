#include<iostream>
#include<math.h>

using namespace std;

int ucln(int a, int b) {
    a = abs(a);
    b = abs(b);
    int r;
    while (b != 0) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

void pstg(int a, int b) {

    int g = ucln(a, b);
    a /= g;
    b /= g;

    if (b < 0) {
        a = -a;
        b = -b;
    }

    cout << a << '/' << b << endl;
}

int main() {
    int a, b;
    cin >> a >> b;
    pstg(a, b);
    return 0;
}

/*
 * ==========================================
 * PHÂN TÍCH ĐỘ PHỨC TẠP (BÀI 4 - RÚT GỌN PHÂN SỐ)
 * ==========================================
 * 1. Time Complexity:
 *    - Best case:    O(1) - Xảy ra khi a chia hết cho b (hoặc b chia hết cho a), dừng sau 1 bước chia.
 *    - Worst case:   O(log(min(|a|, |b|))) - Xảy ra khi a và b là hai số Fibonacci liên tiếp.
 *    - Average case: O(log(min(|a|, |b|))) - Số bước chia dư luôn tỷ lệ thuận với số chữ số của số nhỏ hơn.
 * 
 * 2. Space Complexity:
 *    - Bộ nhớ phụ trợ O(1): do chỉ sử dụng thêm các biến phụ đơn lẻ.
      - Tổng bộ nhớ do đó là O(1).
 * ==========================================
 */