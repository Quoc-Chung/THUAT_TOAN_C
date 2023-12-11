#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

struct NhanVien {
    char HoTen[50];
    int Luong;
    int Ma;
};

void NhapVanBan(NhanVien *nv, int &n, FILE *f = stdout) {
    for (int i = 0; i < n; i++) {
        printf("\nNhap Ho Ten: ");
        fflush(stdin);
        gets(nv[i].HoTen);
        printf("Nhap Luong: ");
        scanf("%d", &nv[i].Luong);
        printf("Nhap Ma Nhan Vien: ");
        scanf("%d", &nv[i].Ma);
    }
}

void XuatDanhSach(NhanVien *nv, int n, FILE *f = stdout) {
    fprintf(f, "%d", n);
    for (int i = 0; i < n; i++) {
        fprintf(f, "\n Ho Ten: %s\nLuong: %d\nMa Nhan Vien: %d", nv[i].HoTen, nv[i].Luong, nv[i].Ma);
    }
}

void SapXep(NhanVien *nv, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (nv[i].Luong < nv[j].Luong) {
                NhanVien tmp = nv[i];
                nv[i] = nv[j];
                nv[j] = tmp;
            }
        }
    }
    printf("\nThong tin nhan vien la:\n");
    for (int i = 0; i < n; i++) {
        printf("\n Ho Ten: %s\nLuong: %d\nMa Nhan Vien: %d", nv[i].HoTen, nv[i].Luong, nv[i].Ma);
    }
}
  // s?p x?p nh?  hon  tang d?n  , l?n hon gi?m d?n  
int main() {
    int n;
    NhanVien *nv;
    FILE *f = fopen("Nhanvien2_2.txt", "w");

    printf("Nhap so luong nhan vien: ");
    scanf("%d", &n);

    nv = (NhanVien *)malloc(n * sizeof(NhanVien));

    NhapVanBan(nv, n, f);
    XuatDanhSach(nv, n, f);
    SapXep(nv, n);

    free(nv);
    fclose(f);
    return 0;
}

