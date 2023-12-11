#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int** DocFile_Matrix(FILE *f, int *m, int *n) {
    fscanf(f, "%d%d", m, n);
    int **a;
    a = (int **)malloc(*m * sizeof(int *));
    for (int i = 0; i < *m; i++) {
        a[i] = (int *)malloc(*n * sizeof(int));
    }
    for (int i = 0; i < *m; i++) {
        for (int j = 0; j < *n; j++) {
            fscanf(f, "%d", &a[i][j]);
        }
    }
    return a;
}
int main() {
    int m, n;
    FILE *f = fopen("Matran.txt", "r");
    int **b = DocFile_Matrix(f, &m, &n);
    printf("\nMa tran duoc doc tu file la:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }
    return 0;
}
