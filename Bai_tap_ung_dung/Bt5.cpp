/*
Bài tập 5. Cho ma trận hai chiều có mm dòng và nn cột, các phần tử là các số nguyên dương. Yêu cầu:
a. Tìm dòng có tổng các phần tử lớn nhất.
b. Sắp xếp các dòng sao cho dòng có tổng lớn hơn nằm phía trên (tức giảm dần theo tổng dòng).
*/

#include <iostream>
using namespace std;

const int MAX = 100; // Kích thước tối đa cho ma trận

// Function prototypes
int tinhTongDong(const int A[][MAX], int m, int n, int row);
int timDongMax(const int A[][MAX], int m, int n);
void sapXepDongGiam(const int A[][MAX], int m, int n);

int main() {
    int m, n;
    int A[MAX][MAX];

    cout << "Nhap so dong m: ";
    cin >> m;
    cout << "Nhap so cot n: ";
    cin >> n;

    // Nhập ma trận
    cout << "Nhap cac phan tu cua ma tran:\n";
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> A[i][j];
        }
    }

    // (a) Tìm dòng có tổng lớn nhất
    int rowMax = timDongMax(A, m, n);
    int maxSum = tinhTongDong(A, m, n, rowMax);
    cout << "\nDong co tong lon nhat la dong thu " << rowMax 
         << " (chi so tu 0), voi tong = " << maxSum << "\n";

    // (b) Sắp xếp các dòng sao cho dòng có tổng lớn hơn nằm phía trên
    // --> Thực hiện trực tiếp hoán đổi các dòng trong ma trận
    sapXepDongGiam(A, m, n);

    // In ma trận sau khi sắp xếp
    cout << "\nMa tran sau khi sap xep cac dong giam dan theo tong:\n";
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cout << A[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}

// Tính tổng của 1 dòng trong ma trận
int tinhTongDong(const int A[][MAX], int m, int n, int row) {
    int sum = 0;
    for(int j = 0; j < n; j++){
        sum += A[row][j];
    }
    return sum;
}

// Tìm chỉ số dòng có tổng lớn nhất
int timDongMax(const int A[][MAX], int m, int n) {
    int rowMax = 0;
    int maxSum = 0;
    for(int i = 0; i < m; i++){
        int sum = tinhTongDong(A, m, n, i);
        if(sum > maxSum) {
            maxSum = sum;
            rowMax = i;
        }
    }
    return rowMax;
}

// Sắp xếp các dòng theo tổng giảm dần
void sapXepDongGiam(const int A[][MAX], int m, int n) {
    // Vì A là tham số const, ta cần 'cast away const' để hoán đổi dòng.
    // Hoặc ta có thể copy A sang 1 mảng khác. Ở đây dùng thủ thuật để hoán đổi.
    int (*B)[MAX] = (int (*)[MAX])A; 
    // Tạo mảng chứa tổng từng dòng
    int sumOfRow[MAX];
    for(int i = 0; i < m; i++){
        sumOfRow[i] = 0;
        for(int j = 0; j < n; j++){
            sumOfRow[i] += B[i][j];
        }
    }
    // Bubble Sort
    for(int i = 0; i < m - 1; i++){
        for(int k = i + 1; k < m; k++){
            if(sumOfRow[i] < sumOfRow[k]){
                // Hoán đổi tổng
                int tempSum = sumOfRow[i];
                sumOfRow[i] = sumOfRow[k];
                sumOfRow[k] = tempSum;
                // Hoán đổi dòng i và k
                for(int col = 0; col < n; col++){
                    int tempVal = B[i][col];
                    B[i][col] = B[k][col];
                    B[k][col] = tempVal;
                }
            }
        }
    }
}