#include <iostream>
using namespace std;

void arrangeEvenOdd(int arr[], int n) {
    int left = 0, right = n - 1;

    // Dùng hai con trỏ để phân tách số chẵn và số lẻ
    while (left < right) {
        // Tìm số lẻ ở phía trái
        while (arr[left] % 2 == 0 && left < right) left++;
        
        // Tìm số chẵn ở phía phải
        while (arr[right] % 2 != 0 && left < right) right--;
        
        // Nếu chưa gặp lẻ ở trái và chẵn ở phải, hoán đổi
        if (left < right) {
            swap(arr[left], arr[right]);
        }
    }
}

int main() {
    int n;
    cout << "Nhap so luong phan tu cua mang: ";
    cin >> n;

    int arr[n]; // Khai báo mảng động
    cout << "Nhap cac phan tu cua mang: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    arrangeEvenOdd(arr, n);

    cout << "Mang sau khi sap xep: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
