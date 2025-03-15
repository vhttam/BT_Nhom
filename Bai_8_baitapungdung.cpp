#include <iostream>
using namespace std;
//Tạo danh sách liên kết A
typedef struct a {
    int info;
    struct a *next;
} A;
A* pHeadA = NULL;
bool IsEmptyA(A* pHead) {
    return (pHead == NULL);
}
//Tạo node A chứa dữ liệu X
A* CreateA(int X) {
    A* p = new A;
    p->info = X;
    p->next = NULL;
    return p;
}
//Kết nối các node chứ dữ liệu X lại
void InsertA(int X) {
    A* temp = pHeadA;
    A* NewNode = CreateA(X);
    if (pHeadA == NULL) {
        pHeadA = NewNode;
    } else {
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = NewNode;
    }
}
//Tạo danh sách liên kết B
typedef struct b {
    int info;
    struct b* next;
} B;
B* pHeadB = NULL;
//Độ lớn của mảng A
int SizeA() {
    int count = 0;
    A* temp = pHeadA;
    while (temp != NULL) {
        temp = temp->next;
        count++;
    }
    return count;
}
void InsertB(int X) {
    B* temp = pHeadB;
    B* NewNode = new B;
    NewNode->info = X;
    NewNode->next = NULL;
    if (pHeadB == NULL) {
        pHeadB = NewNode;
    } else {
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = NewNode;
    }
}
//Hàm chuyển từ hoán vị sang mảng nghịch thể B
void nghich_the() {
    int N = SizeA();
    A* current = pHeadA;
    for (int i = 0; i < N; i++) {
        A* temp = current->next;
        int count = 0;
        while (temp != NULL) {
            if (current->info > temp->info) count++;
            temp = temp->next;
        }
        InsertB(count);
        current = current->next;
    }
}
//Tạo danh sách liên kết C lưu hoán vị
typedef struct c {
    int info;
    struct c* next;
} C;
C* pHeadC = NULL;
void InsertC(int X) {
    C* temp = pHeadC;
    C* NewNode = new C;
    NewNode->info = X;
    NewNode->next = NULL;
    if (pHeadC == NULL) {
        pHeadC = NewNode;
    } else {
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = NewNode;
    }
}
//Tạo danh sách D lưu mảng hoán vị
typedef struct d {
    int info;
    struct d* next;
} D;
D* pHeadD = NULL;
void InsertD(int X) {
    D* temp = pHeadD;
    D* NewNode = new D;
    NewNode->info = X;
    NewNode->next = NULL;
    if (pHeadD == NULL) {
        pHeadD = NewNode;
    } else {
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = NewNode;
    }
}
//Hàm chuyển từ nghịch thể sang hoán vị
/*
Ý tưởng: Định nghĩa mảng nghịch thể là mảng mà trong mảng hoán vị nếu số đứng thứ i có n phần tử bé hơn nó đứng sau nó thì nó có n nghịch thể
-> Khi B[1]=4-> có 4 phần tử bé hơn nó đứng phía sau-> bỏ 4 phần tử đầu thì còn số 5 add nó vào mảng D sau đó xóa
-> B[2]=7-> có 7 phần tử đứng sau nó mà bé hơn nó-> bỏ số 5 rồi thì còn 1,2,3,4,6,7,8 là 7 phần tử bé nhất còn lại và phần tử lớn hơn đám đó là 9
-> CỨ thế lặp lại đến hết danh sách
Ví dụ:
        Mảng A là (5,9,1,8,2,6,4,7,3)
        Mảng B sẽ là (4,7,0,5,0,2,1,1,0)
        Mảng C là (1,2,3,4,5,6,7,8,9)
        current B khúc đầu sẽ là 4
        Lặp i từ 0 đến N
        {
           Lặp j từ 0 đến currentB là 4
           Theo mảng C vị trí thứ 4 là 4 nhưng tempC trỏ đến phần tử kế tiếp->mảng D sẽ nhập 5 vào
        }
           Xóa 5
           Mảng C còn (1,2,3,4,6,7,8,9)
           Xét tiếp phần tử kế tiếp trong B
           tempC sẽ trỏ đến 9->mảng D sẽ nhập 9 vào
           Xóa 9
           Xét tiếp phần tử kế tiếp trong B
           Cứ thế lặp lại đến hết danh sách
*/
void nghich_the_sang_hoan_vi() {
    int N = SizeA();
    //CurrentB trỏ đến từng phần tử mảng B
    B* currentB = pHeadB;
    // Tạo danh sách C chứa các số từ 1 đến N
    for (int i = 1; i < N+1; i++) {
        InsertC(i);
    }
    //Vòng lặp i
    for (int i = 0; i < N; i++) {
        //Dùng Count để lưu giá trị mà currentB trỏ tới, để dùng tỏng vòng lặp j
        int Count = currentB->info;
        //Cho tempC = phần tử đầu tiên trong C
        C* tempC = pHeadC;
        //Prev sẽ lưu phần tử của tempC cũ khi tempC trỏ đến vị trí tiếp theo
        C* prev = NULL;
        //Vòng lặp j
        for (int j = 0; j < Count; j++) {
            prev = tempC;
            //tempC trỏ đến vị trí kế tiếp trong danh sách C
            tempC = tempC->next;
        }
        //Lưu vào danh sách D
        InsertD(tempC->info);
        //Nếu prev = NULL thì pHeadC sẽ là phần tử tiếp theo của tempC
        if (prev == NULL) {
            pHeadC = tempC->next;
        } else {
            //Nếu không thì prev->next = phần tử kế tiếp của tempC
            prev->next = tempC->next;
        }
        //Xóa phần tử tempC sau khi đã add vào D
        delete tempC;
        //Duyệt tiếp phần tử kế tiếp trong mảng B
        currentB = currentB->next;
    }
    cout << endl;
}
void ShowListB() {
    if (pHeadB == NULL) {
        cout << "Danh sach rong\n";
    } else {
        for (B* p = pHeadB; p != NULL; p = p->next) {
            cout << p->info << " ";
        }
        cout << endl;
    }
}
void ShowListD() {
    if (pHeadD == NULL) {
        cout << "Danh sach rong\n";
    } else {
        for (D* p = pHeadD; p != NULL; p = p->next) {
            cout << p->info << " ";
        }
        cout << endl;
    }
}
int main() {
    int n;
    cin >> n;
    int X;
    for (int i = 0; i < n; i++) {
        cin >> X;
        InsertA(X);
    }
    nghich_the();
    ShowListB();
    nghich_the_sang_hoan_vi();
    ShowListD();
    return 0;
}
