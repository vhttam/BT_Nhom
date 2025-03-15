#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

#define MAX 1000
#define SV "SINHVIEN.DAT"
#define SVMASO "SVMASO.IDX"
#define SVTH "SVTH.IDX"
#define SVDTB "SVDTB.IDX"

struct SinhVien {
    int MS;
    char Hovatendem[21];
    char Ten[41];
    int ngay, thang, nam;
    int Phai;  // 0: Nữ, 1: Nam
    float DTB;
};

struct DanhSach {
    SinhVien Sv[MAX];
    int size;
} ds;
//Kiểm tra xem có bị trùng mã số không
bool IsDuplicateMS(int ms, int count) {
    for (int i = 0; i < count; i++) {
        if (ds.Sv[i].MS == ms) {
            return true;
        }
    }
    return false;
}
//hàm swap 2 phần tử kế nhau
void Swap(SinhVien &a, SinhVien &b) {
    SinhVien temp = a;
    a = b;
    b = temp;
}
//Nhap thong tin cac sinh vien vao danh sach
void InputData(int n) {
    //Tao file writing text
    FILE *file = fopen(SV, "wt");
    if (file == NULL) {
        cout << "Không thể mở file để ghi!\n";
        return;
    }
    ds.size = n;
    for (int i = 0; i < ds.size; i++) {
        int ms;
        do {
            cout << "Moi nhap ma so sinh vien: ";
            cin >> ms;
            if (IsDuplicateMS(ms, i)) {
                cout << "Ma so sinh vien da ton tai. Vui long nhap lai!\n";
            }
            else
            cout<<"Ma so sinh vien khong hop le";
        } while (IsDuplicateMS(ms, i));
        ds.Sv[i].MS = ms;
// Nhap thong tin
        cin.ignore();
        cout << "Moi nhap ho va ten dem: ";
        cin.getline(ds.Sv[i].Hovatendem, 21);
        cout << "Moi nhap ten: ";
        cin.getline(ds.Sv[i].Ten, 41);
        cout << "Moi nhap ngay thang nam (ngay thang nam): ";
        cin >> ds.Sv[i].ngay >> ds.Sv[i].thang >> ds.Sv[i].nam;
        cout << "Moi nhap phai (0: Nu, 1: Nam): ";
        cin >> ds.Sv[i].Phai;
        cout << "Moi nhap diem trung binh cua sinh vien: ";
        cin >> ds.Sv[i].DTB;
// Luu vao file SINHVIEN
        fprintf(file, "%d\n",ds.Sv[i].MS);
        fprintf(file, "%s\n",ds.Sv[i].Hovatendem);
        fprintf(file, "%s\n",ds.Sv[i].Ten);
        fprintf(file, "%d %d %d\n",ds.Sv[i].ngay,ds.Sv[i].thang,ds.Sv[i].nam);
        fprintf(file,"%d\n",ds.Sv[i].Phai);
        fprintf(file,"%.2f\n",ds.Sv[i].DTB);
    }
    fclose(file);
}
//Sắp xếp theo mã số bằng Bubble Sort không cờ
void SortByMS() {
    for (int i = ds.size -1; i >= 1; i--) {
        for (int j = 0; j <= i -1; j++) {
            if (ds.Sv[j].MS > ds.Sv[i].MS) {
                Swap(ds.Sv[i], ds.Sv[j]);
            }
        }
    }
}
//Sắp xếp theo tên bằng Interchange Sort 
void SortByName() {
    for (int i = 0; i < ds.size - 1; i++) {
        for (int j = i + 1; j < ds.size; j++) {
            if (strcmp(ds.Sv[i].Ten, ds.Sv[j].Ten) > 0 || (strcmp(ds.Sv[i].Ten, ds.Sv[j].Ten) == 0 && strcmp(ds.Sv[i].Hovatendem, ds.Sv[j].Hovatendem) > 0)) {
                Swap(ds.Sv[i], ds.Sv[j]);
            }
        }
    }
}
//Sắp xếp bằng Interchange Sort 
void SortByDTB() {
    for (int i = 0; i < ds.size - 1; i++) {
        for (int j = i + 1; j < ds.size; j++) {
            if (ds.Sv[i].DTB < ds.Sv[j].DTB) {
                Swap(ds.Sv[i], ds.Sv[j]);
            }
        }
    }
}
//In ra màn hình 
void ShowData() {
    cout << "\nDanh sách sinh viên:\n";
    for (int i = 0; i < ds.size; i++) {
        cout <<"Mã số sinh viên: "<< ds.Sv[i].MS << " \n"; 
        cout<<"Họ và tên sinh viên: "<< ds.Sv[i].Hovatendem << " " << ds.Sv[i].Ten<<"\n";
        cout<<"Ngày tháng năm sinh của sinh viên: "<< ds.Sv[i].ngay << "/" << ds.Sv[i].thang << "/" << ds.Sv[i].nam <<"\n";
        cout<<"Giới tính: "<< (ds.Sv[i].Phai ? "Nam" : "Nữ")<<"\n";
        cout<<"Điểm trung bình của sinh viên: "<<ds.Sv[i].DTB << endl;
    }
}

int main() {
    int n;
    //Điều kiện không được dưới 10 sinh viên
    do {
        cout << "Nhập số lượng sinh viên (>= 10): ";
        cin >> n;
    } while (n < 10);

    InputData(n);
    cout << "\nDanh sách ban đầu:";
    ShowData();

    cout << "\nSắp xếp theo Mã Số:";
    SortByMS();
    ShowData();

    cout << "\nSắp xếp theo Tên:";
    SortByName();
    ShowData();

    cout << "\nSắp xếp theo Điểm Trung Bình:";
    SortByDTB();
    ShowData();

    return 0;
}
/*
Nhận xét:
Các thuật toán sắp xếp như Bubble Sort và Interchange Sort dễ hiểu và dễ sử dụng.
Việc sắp xếp theo chỉ mục giúp không phải thay đổi trực tiếp file dữ liệu gốc,
tối ưu cho việc truy vấn nhiều tiêu chí khác nhau. 
Tuy nhiên, nếu dữ liệu thay đổi (thêm, xóa, sửa), 
cần cập nhật lại các chỉ mục
*/
