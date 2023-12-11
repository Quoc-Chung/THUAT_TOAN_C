#include <stdio.h>
#include <stdlib.h> // Thư viện này để cấp phát bộ nhớ động
int main(){
    int n;
    int *a;
    int sum=0;
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);
    
     a=(int *)calloc(n,sizeof(int));// cap phat dong bo nho cho mang a
    // Nếu không thể cấp phát, 
    // hàm malloc sẽ trả về con trỏ NULL
    if (a ==NULL){
        printf("\nLoi khong the cap phat.");
        exit(0);// lệnh dừng tương đương với return ;
    }
    for (int i=1;i<=n;i++){
        printf("\na[%d]:",i); 
        scanf("%d",(a+i));
        sum+=*(a + i);
    }
    printf("Tong = %d \n", sum);
    // in ra  tổng khi chưa cấp phát bộ nhớ thêm 
    //cấp phát bộ nhớ thêm 
    int x;
    printf("Them phan tu:");
    scanf("%d", &x);
    a = (int*)realloc(a, x*sizeof(int));// cấp phát bộ nhớ thêm 
    for (int i =n+1; i <=(n+x);i++){
        printf("\na[%d]: ",i); 
        scanf("\n%d", (a+i));
        sum +=*(a + i);
    }
    printf("Tong moi = %d", sum);
    // Giải phóng vùng nhớ cho con trỏ
    free(a);
    return 0;
}
