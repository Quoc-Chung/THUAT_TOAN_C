#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct hoten {
    char ten[50];
    int tuoi;
};

void nhap_con_tro(struct hoten *ht[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Nhap ho ten: ");
        fflush(stdin);
        fgets(ht[i]->ten, sizeof(ht[i]->ten), stdin);
        printf("Nhap tuoi: ");
        scanf("%d", &ht[i]->tuoi);
        fflush(stdin);
    }
}

void in_bang_con_tro(struct hoten *ht[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Ho ten: %s", ht[i]->ten);
        printf("Tuoi: %d\n", ht[i]->tuoi);
    }
}

int main() {
    int n = 2;
    struct hoten *ht[100];
    for (int i = 0; i < n; i++) {
        ht[i] = (struct hoten *)malloc(sizeof(struct hoten));
    }
    nhap_con_tro(ht, n);
    in_bang_con_tro(ht, n);
    for (int i = 0; i < n; i++) {
        free(ht[i]);
    }
    return 0;
}
