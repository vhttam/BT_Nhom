#include <iostream>

using namespace std;

// Hàm hoán đổi hai số
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Hàm in mảng
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// 1. Sắp xếp đổi chỗ trực tiếp (Interchange Sort)
void interchangeSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                swap(arr[i], arr[j]);
            }
        }
    }
}

// 2. Sắp xếp chọn trực tiếp (Selection Sort)
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

// 3. Sắp xếp chèn trực tiếp (Insertion Sort)
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// 4. Sắp xếp nổi bọt (Bubble Sort)
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {
    int n;

    // Nhập số lượng phần tử
    cout << "Nhap so luong phan tu cua mang: ";
    cin >> n;

    int arr[n], arr1[n], arr2[n], arr3[n], arr4[n];

    // Nhập các phần tử của mảng
    cout << "Nhap " << n << " so nguyen: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Sao chép dữ liệu từ arr sang các mảng khác
    for (int i = 0; i < n; i++) {
        arr1[i] = arr[i];
        arr2[i] = arr[i];
        arr3[i] = arr[i];
        arr4[i] = arr[i];
    }

    cout << "Mang ban dau: ";
    printArray(arr, n);

    interchangeSort(arr1, n);
    cout << "Sau Interchange Sort: ";
    printArray(arr1, n);

    selectionSort(arr2, n);
    cout << "Sau Selection Sort: ";
    printArray(arr2, n);

    insertionSort(arr3, n);
    cout << "Sau Insertion Sort: ";
    printArray(arr3, n);

    bubbleSort(arr4, n);
    cout << "Sau Bubble Sort: ";
    printArray(arr4, n);

    return 0;
}
