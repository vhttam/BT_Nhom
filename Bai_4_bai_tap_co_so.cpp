#include <iostream>
#include <cstdio>
#include <cstdlib>
//Thư viện để đo thời gian
#include <chrono>
using namespace std;
using namespace chrono;

// Tạo danh sách liên kết A
typedef struct a {
    int info;
    struct a *next;
} A;
A* pHeadA = NULL;

bool IsEmptyA(A* pHead) {
    return (pHead == NULL);
}

// Tạo node A chứa dữ liệu X
A* CreateA(int X) {
    A* p = new A;
    p->info = X;
    p->next = NULL;
    return p;
}

// Kết nối các node chứa dữ liệu X lại
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

// Hàm ghi số ngẫu nhiên vào file
void generateRandomNumbersToFile(const char* filePath, int count) {
    FILE* file = fopen(filePath, "wt");
    if (file == NULL) {
        cerr << "Không thể mở file" << endl;
        return;
    }
    for (int i = 0; i < count; ++i) {
        fprintf(file, "%d\n", rand() % 100000); //Random 
    }
    fclose(file);
}

// Đo thời gian
double measureTime(void (*sortFunc)()) {
    auto start = high_resolution_clock::now();
    sortFunc();
    auto stop = high_resolution_clock::now();
    return duration_cast<duration<double>>(stop - start).count();//Tính thời gian bằng cách lấy thời gian kết thúc trừ cho thời gian bắt đầu 
}

// Đọc dữ liệu từ file
void readData(const char* filePath) {
    FILE* file = fopen(filePath, "r");
    int value;
    while (fscanf(file, "%d", &value) != EOF) {
        InsertA(value);
    }
    fclose(file);
}

// In danh sách liên kết
void printList() {
    A* temp = pHeadA;
    while (temp != NULL) {
        cout << temp->info << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Ghi kết quả ra file
void writeResults(const char* filePath, const char* algorithm, double duration) {
    FILE* file = fopen(filePath, "a");
    //In thời gian chạy các cách sắp xếp ra với 5 chữ số thập phân
    fprintf(file, "%s: %.5f seconds\n", algorithm, duration);
    A* temp = pHeadA;
    while (temp != NULL) {
        fprintf(file, "%d ", temp->info);
        temp = temp->next;
    }
    fprintf(file, "\n\n");
    fclose(file);
}

// Interchange Sort
void interchangeSort() {
    for (A* i = pHeadA; i; i = i->next) {
        for (A* j = i->next; j; j = j->next) {
            if (i->info > j->info) swap(i->info, j->info);
        }
    }
}

// Selection Sort
void selectionSort() {
    for (A* i = pHeadA; i; i = i->next) {
        A* minNode = i;
        for (A* j = i->next; j; j = j->next) {
            if (j->info < minNode->info) minNode = j;
        }
        swap(i->info, minNode->info);
    }
}

// Insertion Sort
void insertionSort() {
    if (!pHeadA || !pHeadA->next) return;
    A* sorted = NULL;
    A* current = pHeadA;
    while (current != NULL) {
        A* next = current->next;
        if (!sorted || sorted->info >= current->info) {
            current->next = sorted;
            sorted = current;
        } else {
            A* temp = sorted;
            while (temp->next != NULL && temp->next->info < current->info) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
        current = next;
    }
    pHeadA = sorted;
}

// Bubble Sort
void bubbleSort() {
    bool swapped;
    A* ptr1;
    A* lptr = NULL;
    if (pHeadA == NULL) return;
    do {
        swapped = false;
        ptr1 = pHeadA;
        while (ptr1->next != lptr) {
            if (ptr1->info > ptr1->next->info) {
                swap(ptr1->info, ptr1->next->info);
                swapped = true;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

int main() {
    srand(time(0));
    generateRandomNumbersToFile("input.txt", 30000);

    struct Algorithm {
        const char* name;
        void (*func)();
    } algorithms[] = {
        {"Interchange Sort", interchangeSort},
        {"Selection Sort", selectionSort},
        {"Insertion Sort", insertionSort},
        {"Bubble Sort", bubbleSort}
    };

    for (const auto& algo : algorithms) {
        pHeadA = NULL;
        readData("input.txt");
        double duration = measureTime(algo.func);
        writeResults("output.txt", algo.name, duration);
        cout << algo.name << ": " << duration << " seconds" << endl;
    }

    cout << "Sorted List: ";
    printList();

    return 0;
}

