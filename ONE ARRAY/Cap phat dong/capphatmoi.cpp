#include <stdio.h>
#include <math.h>
#include<stdlib.h>

int main (){
    int n;
    printf("Nhap so luong mang ban dau :");
    scanf("%d",&n);

    // cấp phát vừa đủ bộ nhớ  
    int *a; // khai báo mảng con tro
    // cấp phat mảng 
    // hàm cấp phát luôn trả về kiểu void nên ta phải ép nó sang kiểu của mảng 
    a = (int *)malloc(n*sizeof(int));

    // nhập mảng 
    for (int i=0;i<n;i++){
        scanf("%d",(a+i)); // đây là số khi ép sang kiểu con trỏ 
    }

    printf("\nMang in ra la :\n");
    for (int i=0;i<n;i++){
        printf("%d ",*(a+i));
    }

    // nhap so luong phan tu cap phat them 
    int x;
    printf("\nNhap so luong cap phat them:");
    scanf("%d",&x);

    // tạo một mảng mới chứa tất cả các phần tử 
    int *b=(int *) malloc(x*sizeof(int));
    if(b==NULL){
        printf("\nkhong cap phat duoc them.");
        exit(1);
    }

    // nhap phan tu cap phat them 
    for (int i=n;i<x;i++){
        scanf("%d",b+i);
    }

    // sao chép các phần tử từ mảng b sang mảng a từ vị trí n đến vị trí x-1
    for (int i=n;i<n+x;i++){
        *(a+i)=*(b+i);
    }

    free(b);

    // in ra các phần tử của mảng a bao gồm các phần tử ban đầu và các phần tử mới cấp phát
    for (int i=0;i<n+x;i++){
        printf("%d ",a[i]);
    }

    free(a);
}
