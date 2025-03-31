/*
Bài 1. Cho một dãy gồm n số nguyên (lưu trong mảng tĩnh). Yêu cầu:
a. Tìm vị trí của k phần tử có giá trị lớn nhất trong dãy.
b. Sắp xếp các phần tử tăng dần theo tổng các chữ số của từng phần tử.
c. Xóa tất cả các số nguyên tố có trong dãy.
*/

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

const int MAX = 100;

// Cấu trúc lưu cặp (giá trị, vị trí)
struct Pair {
    int value;
    int index;
};

// Function prototypes
bool cmpPair(const Pair &a, const Pair &b);
int tongChuSo(int n);
bool cmpSum(int a, int b);
bool laSoNguyenTo(int n);

int main() {
    int n, k;
    int a[MAX];

    cout << "Nhap so phan tu cua day: ";
    cin >> n;
    cout << "Nhap cac phan tu (cach nhau boi khoang trang): ";
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    cout << "Nhap k (so phan tu lon nhat can tim vi tri): ";
    cin >> k;
    
    // (a) Tìm vị trí của k phần tử có giá trị lớn nhất
    Pair arr[MAX];
    for (int i = 0; i < n; i++){
        arr[i].value = a[i];
        arr[i].index = i;
    }
    sort(arr, arr + n, cmpPair);
    cout << "\nVi tri cua " << k << " phan tu co gia tri lon nhat: ";
    for (int i = 0; i < k && i < n; i++){
        cout << arr[i].index << " ";
    }
    cout << "\n";

    // (b) Sắp xếp các phần tử theo tổng các chữ số
    int b[MAX];
    for (int i = 0; i < n; i++){
        b[i] = a[i];
    }
    sort(b, b + n, cmpSum);
    cout << "Day sau khi sap xep theo tong cac chu so: ";
    for (int i = 0; i < n; i++){
        cout << b[i] << " ";
    }
    cout << "\n";

    // (c) Xóa tất cả các số nguyên tố có trong dãy
    int newN = 0;
    for (int i = 0; i < n; i++){
        if (!laSoNguyenTo(a[i])) {
            a[newN++] = a[i];
        }
    }
    cout << "Day sau khi xoa cac so nguyen to: ";
    for (int i = 0; i < newN; i++){
        cout << a[i] << " ";
    }
    cout << "\n";

    return 0;
}

// Function definitions

// So sánh các cặp theo giá trị giảm dần
bool cmpPair(const Pair &a, const Pair &b) {
    return a.value > b.value;
}

// Tính tổng các chữ số của một số nguyên
int tongChuSo(int n) {
    n = abs(n);
    int sum = 0;
    while(n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

// So sánh hai số theo tổng các chữ số (nếu bằng nhau, so sánh trực tiếp giá trị)
bool cmpSum(int a, int b) {
    int sumA = tongChuSo(a);
    int sumB = tongChuSo(b);
    if(sumA == sumB)
        return a < b;
    return sumA < sumB;
}

// Kiểm tra số nguyên tố
bool laSoNguyenTo(int n) {
    if(n < 2)
        return false;
    for (int i = 2; i * i <= n; i++){
        if(n % i == 0)
            return false;
    }
    return true;
}