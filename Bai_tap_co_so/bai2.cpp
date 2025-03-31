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

// Hàm chia mảng cho QuickSort
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Chọn phần tử chốt
    int i = low - 1; // Vị trí nhỏ hơn pivot

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Hàm sắp xếp nhanh (đệ quy) - QuickSort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Hàm trộn hai mảng con cho MergeSort
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int* L = new int[n1];  // Dynamically allocate memory
    int* R = new int[n2];  // Dynamically allocate memory

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    delete[] L; // Free the dynamically allocated memory
    delete[] R; // Free the dynamically allocated memory
}

// Hàm sắp xếp trộn - MergeSort
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Hàm điều chỉnh heap cho HeapSort
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) largest = left;
    if (right < n && arr[right] > arr[largest]) largest = right;
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

// Hàm sắp xếp heap - HeapSort
void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    int arr[SIZE];
    taoMangNgauNhien(arr, SIZE);

    // Copying the original array for each sorting algorithm
    int quickArr[SIZE], mergeArr[SIZE], heapArr[SIZE];

    // Copy original array into all the arrays for sorting
    for (int i = 0; i < SIZE; i++) {
        quickArr[i] = arr[i];
        mergeArr[i] = arr[i];
        heapArr[i] = arr[i];
    }

    clock_t start, end;

    // QuickSort
    start = clock();
    quickSort(quickArr, 0, SIZE - 1);
    end = clock();
    cout << "Quick Sort: " << (double)(end - start) / CLOCKS_PER_SEC << " giay\n";

    // MergeSort
    start = clock();
    mergeSort(mergeArr, 0, SIZE - 1);
    end = clock();
    cout << "Merge Sort: " << (double)(end - start) / CLOCKS_PER_SEC << " giay\n";

    // HeapSort
    start = clock();
    heapSort(heapArr, SIZE);
    end = clock();
    cout << "Heap Sort: " << (double)(end - start) / CLOCKS_PER_SEC << " giay\n";

    return 0;
}
