/*
Bài tập 3. Cho thông tin về các phòng thi tại một hội đồng thi, mỗi phòng có các thông tin:
- Số phòng: số nguyên từ 1 đến 200
- Nhà: một chữ cái in hoa từ A đến Z
- Khả năng chứa: số nguyên từ 10 đến 250
a. Định nghĩa cấu trúc dữ liệu lưu trữ các phòng thi.
b. Với cấu trúc đã định nghĩa, vận dụng thuật toán sắp xếp để thực hiện các công việc sau:
    (1) Sắp xếp và in danh sách các phòng thi theo thứ tự giảm dần về khả năng chứa.
    (2) Sắp xếp và in danh sách các phòng thi theo thứ tự tăng dần theo Nhà (A → Z);
        với các phòng cùng một nhà thì sắp xếp theo thứ tự tăng dần theo Số phòng.
    (3) Sắp xếp và in danh sách các phòng thi theo thứ tự tăng dần theo Nhà (A → Z);
        với các phòng cùng một nhà thì sắp xếp theo thứ tự giảm dần theo khả năng chứa.
*/

#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 100; // Giả sử số phòng thi không vượt quá MAX

// Định nghĩa cấu trúc PhongThi
struct PhongThi {
    int soPhong;    // Số phòng (1 - 200)
    char nha;       // Nhà (A - Z)
    int chua;       // Khả năng chứa (10 - 250)
};

// Function prototypes
bool cmpGiamTheoChua(const PhongThi &p1, const PhongThi &p2);
bool cmpTangTheoNhaVaSoPhong(const PhongThi &p1, const PhongThi &p2);
bool cmpTangTheoNhaVaGiamTheoChua(const PhongThi &p1, const PhongThi &p2);
void inDanhSachPhong(PhongThi phong[], int n);

int main() {
    int n;
    PhongThi phong[MAX];
    
    cout << "Nhap so luong phong thi: ";
    cin >> n;
    
    // Nhập thông tin cho từng phòng thi
    for (int i = 0; i < n; i++){
        cout << "\nNhap thong tin phong thu " << i+1 << ":\n";
        cout << "  So phong: ";
        cin >> phong[i].soPhong;
        cout << "  Nha: ";
        cin >> phong[i].nha;
        cout << "  Khả nang chua: ";
        cin >> phong[i].chua;
    }
    
    // 1. Sắp xếp theo khả năng chứa giảm dần
    PhongThi phong1[MAX];
    for (int i = 0; i < n; i++){
        phong1[i] = phong[i];
    }
    sort(phong1, phong1 + n, cmpGiamTheoChua);
    cout << "\nDanh sach phong thi sap xep giam dan theo kha nang chua:\n";
    inDanhSachPhong(phong1, n);
    
    // 2. Sắp xếp tăng dần theo Nhà (A->Z), nếu cùng nhà thì tăng dần theo Số phòng
    PhongThi phong2[MAX];
    for (int i = 0; i < n; i++){
        phong2[i] = phong[i];
    }
    sort(phong2, phong2 + n, cmpTangTheoNhaVaSoPhong);
    cout << "\nDanh sach phong thi sap xep tang dan theo Nha, neu cung nha thi tang dan theo so phong:\n";
    inDanhSachPhong(phong2, n);
    
    // 3. Sắp xếp tăng dần theo Nhà (A->Z), nếu cùng nhà thì giảm dần theo khả năng chứa
    PhongThi phong3[MAX];
    for (int i = 0; i < n; i++){
        phong3[i] = phong[i];
    }
    sort(phong3, phong3 + n, cmpTangTheoNhaVaGiamTheoChua);
    cout << "\nDanh sach phong thi sap xep tang dan theo Nha, neu cung nha thi giam dan theo kha nang chua:\n";
    inDanhSachPhong(phong3, n);
    
    return 0;
}

// In danh sách các phòng thi
void inDanhSachPhong(PhongThi phong[], int n) {
    cout << "So phong\tNha\tKha nang chua\n";
    for (int i = 0; i < n; i++){
        cout << phong[i].soPhong << "\t\t" << phong[i].nha << "\t" << phong[i].chua << "\n";
    }
}

// So sánh giảm dần theo khả năng chứa
bool cmpGiamTheoChua(const PhongThi &p1, const PhongThi &p2) {
    return p1.chua > p2.chua;
}

// So sánh tăng dần theo Nhà; nếu cùng nhà thì tăng dần theo Số phòng
bool cmpTangTheoNhaVaSoPhong(const PhongThi &p1, const PhongThi &p2) {
    if(p1.nha != p2.nha)
        return p1.nha < p2.nha;
    return p1.soPhong < p2.soPhong;
}

// So sánh tăng dần theo Nhà; nếu cùng nhà thì giảm dần theo khả năng chứa
bool cmpTangTheoNhaVaGiamTheoChua(const PhongThi &p1, const PhongThi &p2) {
    if(p1.nha != p2.nha)
        return p1.nha < p2.nha;
    return p1.chua > p2.chua;
}