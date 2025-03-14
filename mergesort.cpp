#include <iostream>
using namespace std;

// Merge Sort cho sắp xếp tăng dần (cho số chẵn)
void mergeAscending(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int i = 0; i < n2; i++) R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

// Merge Sort cho sắp xếp giảm dần (cho số lẻ)
void mergeDescending(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int i = 0; i < n2; i++) R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] >= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

// Hàm merge sort chung
void mergeSort(int arr[], int left, int right, bool ascending) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid, ascending);
        mergeSort(arr, mid + 1, right, ascending);

        if (ascending) mergeAscending(arr, left, mid, right);
        else mergeDescending(arr, left, mid, right);
    }
}

// Hàm chính để sắp xếp theo yêu cầu
void customSort(int arr[], int n) {
    int even[n], odd[n];
    int evenCount = 0, oddCount = 0;

    // Tạo mảng chẵn, lẻ
    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) {
            if (arr[i] % 2 == 0) even[evenCount++] = arr[i];
            else odd[oddCount++] = arr[i];
        }
    }

    // Sắp xếp số chẵn tăng dần, số lẻ giảm dần
    mergeSort(even, 0, evenCount - 1, true);
    mergeSort(odd, 0, oddCount - 1, false);

    // Ghép lại vào mảng gốc, giữ nguyên số 0
    int evenIdx = 0, oddIdx = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) {
            if (arr[i] % 2 == 0) arr[i] = even[evenIdx++];
            else arr[i] = odd[oddIdx++];
        }
    }
}

// Hàm in mảng
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Hàm main
int main() {
    int n;
    cout << "Nhap so luong phan tu cua mang: ";
    cin >> n;

    int arr[n];  // Khai báo mảng động

    cout << "Nhap cac phan tu cua mang: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Mang ban dau: ";
    printArray(arr, n);

    customSort(arr, n);

    cout << "Mang sau khi sap xep: ";
    printArray(arr, n);

    return 0;
}
