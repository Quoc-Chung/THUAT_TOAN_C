#include <stdio.h>
#include <math.h>
#include <stdlib.h>
void DocFile(int** a, int& n, char* tentep) {
    FILE* f = fopen(tentep, "r");
    if (f == NULL) {
        printf("\nKhong the mo duoc file.");
        exit(0);
    }
    fscanf(f, "%d", &n);
    *a = (int*)malloc((n + 1) * sizeof(int));
    for (int i = 0; i <= n; i++) {
        fscanf(f, "%d", &(*a)[i]);
    }
    printf("\nHe so doc tu tep la:\n");
    for (int i = 0; i <= n; i++) {
        printf("%d ", (*a)[i]);
    }
    fclose(f);
}

int TinhDaThuc(int* a, int n, int x) {
    int Value = a[0];
    for (int i = 1; i <= n; i++) {
        Value += a[i] * pow(x, i);
    }
    return Value;
}

int HamTinhDaoHam(int* a, int n, int x) {
    int DaoHam = 1 * a[1];
    for (int i = 2; i <= n; i++) {
        DaoHam += i * a[i] * pow(x, i - 1);
    }
    return DaoHam;
}

int CongDaThuc(int* a, int n) {
    int m;
    printf("\nNhap kich thuoc ma tran Q: ");
    scanf("%d", &m);
    int* b = (int*)malloc((m + 1) * sizeof(int));
    printf("\nNhap he so:\n");
    for (int i = 0; i <= m; i++) {
        scanf("%d", &b[i]);
    }
    int tong = TinhDaThuc(a, n, 3) + TinhDaThuc(b, m, 3);
    printf("\nTong hai da thuc la: %d", tong);
    free(b);
}

int main() {
    int n;
    int* a;
    char tentep[50] = "dathuc.txt";
    DocFile(&a, n, tentep);
    CongDaThuc(a, n);
    free(a);
    return 0;
}
