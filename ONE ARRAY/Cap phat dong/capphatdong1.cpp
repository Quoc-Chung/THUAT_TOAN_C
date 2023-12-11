#include <stdio.h>
#include <stdlib.h>
void nhap(int *a, int n){
    for (int i = 1; i <= n; i++)
    {
        //nhan gia tri cua nguoi dung nhap vao thong qua scanf va dia chi (ptr + i)
        printf(" Nhap a[%d]:", i);
        scanf("%d", (a + i));// (a+i) tương đương với &a[i];
    }
}
void xuat(int *a, int n){
    for (int i = 1; i <=n;i++)
    {
        //hien thi ra gia tri bang toan tu *(ptr + i)
        printf(" %d \n", *(a + i));
    }
}
int main(){
    int n;
    printf("Nhap n: ");
    scanf("%d",&n);
    //khai bao con tro a và cap phat bo nho bang con tro a
    int  *a = (int*)malloc(n * sizeof(int));
    //nhap mang
    nhap(a,n);
    //xuat mang
    xuat(a,n);
    //giai phong vung nho con tro a
    free(a);
}