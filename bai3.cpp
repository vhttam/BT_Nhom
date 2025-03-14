#include <iostream>
#include <ctime>
using namespace std;

#define SIZE 30000

// Hàm tạo mảng ngẫu nhiên
void taoMangNgauNhien(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100000;  
    }
}

// Hàm phân tách cho thuật toán QuickSort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // Chọn phần tử cuối làm pivot
    int i = low - 1;  // Chỉ số của phần tử nhỏ hơn pivot

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {  // Nếu phần tử nhỏ hơn pivot, đổi chỗ
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);  // Đặt pivot vào đúng vị trí
    return i + 1;
}

// Hàm thực hiện QuickSort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);  // Tìm chỉ số của pivot
        quickSort(arr, low, pi - 1);  // Sắp xếp phần bên trái pivot
        quickSort(arr, pi + 1, high);  // Sắp xếp phần bên phải pivot
    }
}

int main() {
    int arr[SIZE];
    taoMangNgauNhien(arr, SIZE);

    int copyArr[SIZE];
    for (int i = 0; i < SIZE; i++) {
        copyArr[i] = arr[i];
    }

    clock_t start, end;

    start = clock();
    quickSort(copyArr, 0, SIZE - 1);
    end = clock();
    cout << "Quick Sort: " << (double)(end - start) / CLOCKS_PER_SEC << " giay\n";

    return 0;
}
