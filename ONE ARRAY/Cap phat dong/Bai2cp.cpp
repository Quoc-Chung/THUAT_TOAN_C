#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Sach {
    char TenSach[30];
    char TenTacGia[30];
    int NamXuatBan;
} Sach;
// tạo một biến tĩnh (static) ở bên ngoài + biến n
Sach *A;
int n;
// HÀm  nhập truyền vào **A ==> Cấp phát cho *A
void Nhap(int *n, Sach **A) {
    printf("\nNhap so luong sach: ");
    scanf("%d", n);


    *A = (Sach *)malloc((*n) * sizeof(Sach));
    
    
    if (*A == NULL) {
        printf("\nKhong cap phat duoc bo nho.");
        exit(1);
    }

    for (int i = 0; i < *n; i++) {
        printf("\nNhap sach thu %d\n", i + 1);
        printf("Nhap Ten Sach: ");
        fflush(stdin);
        scanf("%s", (*A)[i].TenSach);

        printf("Nhap Ten Tac Gia: ");
        fflush(stdin);
        scanf("%s", (*A)[i].TenTacGia);

        printf("Nhap Nam Xuat Ban: ");
        scanf("%d", &(*A)[i].NamXuatBan);
    }
}

void Xuat(int n, Sach *A) {
    printf("\nTHONG TIN CUON SACH\n");
    for (int i = 0; i < n; i++) {
        printf("\nTen Sach: %s", A[i].TenSach);
        printf("\nTen Tac Gia: %s", A[i].TenTacGia);
        printf("\nNam Xuat Ban: %d", A[i].NamXuatBan);
        printf("\n");
    }
}

int DemSach(int n, Sach *a) {
    char TenSearch[30];
    printf("\nNhap ten tim kiem: ");
    fflush(stdin);
    scanf("%s", TenSearch);

    int dem = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(TenSearch, a[i].TenTacGia) == 0) {
            dem++;
        }
    }
    return dem;
}
void Thongke(int n, Sach *a) {
    int count[100006] = {0};
    for (int i = 0; i < n; i++) {
        count[a[i].NamXuatBan]++;
    }

    for (int i = 0; i < 100006; i++) {
        if (count[i] > 0) {
            printf("%d: %d Cuon\n", i, count[i]);
        }
    }
}

int Menu() {
    int chon;
    do {
        printf("\n1. Nhap n cuon sach");
        printf("\n2. Xuat n cuon sach");
        printf("\n3. Dem theo tac gia");
        printf("\n4. Thong ke");
        printf("\n5. Thoat");
        printf("\nChon chuc nang: ");
        scanf("%d", &chon);
// sử dụng các biến tính để  có thể truy cập vào hàm menu trống  đối số:
//Sach *A;
//int n;
        switch (chon) {
            case 1: {
                Nhap(&n, &A); // truyền vào **A và *n
                break;
            }
            case 2: {
                Xuat(n, A);// truyền vào n,*A
                break;
            }
            case 3: {
                int dem = DemSach(n, A);
                printf("\nSo Sach cua tac gia vua nhap la: %d", dem);
                break;
            }
            case 4: {
                Thongke(n, A);
                break;
            }
        }
    } while (chon != 5);
}

int main() {
    Menu();
    free(A);
    return 0;
}

           
