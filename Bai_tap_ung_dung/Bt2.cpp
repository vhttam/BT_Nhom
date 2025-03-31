/*
Bài tập 2. Thông tin về mỗi số hạng của một dãy thức bậc n bao gồm: Hệ số – là một số thực,
Bậc – là một số nguyên có giá trị từ 0 đến 100.
a. Hãy định nghĩa cấu trúc dữ liệu để lưu trữ các dữ liệu trong bộ nhớ trong của máy tính.
b. Với cấu trúc dữ liệu đã được định nghĩa, hãy vận dụng một thuật toán sắp xếp và cài đặt
chương trình thực hiện việc sắp xếp các số hạng trong dãy theo thứ tự tăng dần của các bậc.
*/

#include <iostream>
#include <iomanip>
using namespace std;

const int MAX_TERMS = 101;  // Số lượng số hạng tối đa

// Định nghĩa cấu trúc lưu trữ số hạng của đa thức
struct Term {
    float coefficient;  // Hệ số của số hạng
    int degree;         // Bậc của số hạng (0 đến 100)
};

// Function prototypes
void selectionSort(Term poly[], int n);
void swap(Term &a, Term &b);
void printPolynomial(const Term poly[], int n);

int main() {
    int n;
    Term poly[MAX_TERMS];

    cout << "Nhap so luong so hang: ";
    cin >> n;

    // Nhập dữ liệu cho từng số hạng
    for (int i = 0; i < n; i++) {
        cout << "Nhap he so va bac cua so hang thu " << i+1 << " (cach nhau boi khoang trang): ";
        cin >> poly[i].coefficient >> poly[i].degree;
    }

    // In đa thức trước khi sắp xếp
    cout << "\nDa thuc truoc khi sap xep:\n";
    printPolynomial(poly, n);

    // Sắp xếp các số hạng theo thứ tự tăng dần của bậc
    selectionSort(poly, n);

    // In đa thức sau khi sắp xếp
    cout << "\nDa thuc sau khi sap xep theo bac tang dan:\n";
    printPolynomial(poly, n);

    return 0;
}
// Function definitions

// Hàm sắp xếp các số hạng theo bậc tăng dần sử dụng Selection Sort
void selectionSort(Term poly[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (poly[j].degree < poly[minIndex].degree) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(poly[i], poly[minIndex]);
        }
    }
}

// Hàm hoán đổi 2 số hạng
void swap(Term &a, Term &b) {
    Term temp = a;
    a = b;
    b = temp;
}

// Hàm in đa thức ra màn hình
void printPolynomial(const Term poly[], int n) {
    // In theo định dạng: coefficient*x^degree (hệSố*x^bậc)
    for (int i = 0; i < n; i++) {
        cout << fixed << setprecision(2) << poly[i].coefficient << "*x^" << poly[i].degree << "  ";
    }
    cout << endl;
}