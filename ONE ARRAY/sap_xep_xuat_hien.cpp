#include <iostream>

using namespace std;

void swap(int *a, int *b) {
    int tam = *a;
    *a = *b;
    *b = tam;
}
//
//void arrange(int a[], int n) {
//    int max_value = a[0];
//    for (int i = 1; i < n; i++) {
//        if (a[i] > max_value) {
//            max_value = a[i];
//        }
//    }
//    int count2[max_value + 1] = {0}; // khởi tạo tất cả các phần tử trong mảng count2 bằng 0
//    for (int i = 0; i < n; i++) {
//        count2[a[i]]++;
//    }
//    cout << "\nThu tu cac so sap xep theo su xuat hien :" << endl;
//    for (int i = 0; i <= max_value; i++) {
//        for (int j = i + 1; j <= max_value; j++) {
//            if (count2[i] > count2[j]) {
//                swap(&count2[i], &count2[j]);
//            }
//        }
//        if (count2[i] > 0) {
//            for (int k = 0; k < count2[i]; k++) {
//                cout << i << " ";
//            }
//        }
//    }
//}
//void swap(int *a, int *b) {
//    int tam = *a;
//    *a = *b;
//    *b = tam;
//}
int count2[1000006] = {0}; 
void arrange(int a[], int n) {
    int max = a[0];
    for (int i = 0; i < n; i++) {
        count2[a[i]]++;
    }
    cout << "\nThu tu cac so sap xep theo su xuat hien :" << endl;
    for (int i = 0; i <= 1000006; i++) {
        for (int j = i + 1; j <=1000006; j++) {
            if (count2[i] > count2[j]) {
                swap(&count2[i],&count2[j]);
            }
        }
        if (count2[i] > 0) {
            for (int k = 0; k < count2[i]; k++) {
                cout << i << " ";
            }
        }
    }
}
int main() {
    int a[] = {2,3,1,2,3};
    int n = sizeof(a) / sizeof(int);
    arrange(a, n);
    return 0;
}
