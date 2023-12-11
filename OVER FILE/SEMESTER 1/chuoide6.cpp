#include <stdio.h>
#include <math.h>
void nhapmang(int a[],int n){
    for (int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
}
void inmang(int a[],int n){
    printf("Mang la :\n");
    for (int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
}
void kiemtradoixung (int a[],int n){
    int flag=0;
    //  gia tri :   1   2   3   4   5
    //  vị trí  :   0   1   2   3   4
    // ta thây rằng mỗi vòng lặp ta sẽ kiểm tra hai gia tri cùng lúc
    // nên chỉ cần chạy một nửa mảng 
    // ở đây chỉ chạy đến số 0 và số 1 nên  vòng for chạy từ 0 đến (n-2)/2;
    for (int i=0;i<(n-2)/2;i++){
        if(a[i]!=a[n-1-i]){
            flag++;
            break;
        }
    }
    if(flag==0){
        printf("\nMang doi xung ");
    }
    else if(flag>0){
        printf("\nMang khong doi xung");
    }
}
int main (){
    int n;
    int a[100];
    printf("Nhap n:");
    scanf("%d",&n);
    nhapmang(a,n);
    inmang(a,n);
    kiemtradoixung(a,n);
    return 0;

}
