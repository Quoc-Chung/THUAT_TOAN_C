#include <stdio.h>
#include <math.h>

void NhapMang(int *a, int n)
{
    for (int i = 0; i < n;i++){
        printf("\nNhap vao a[%d] = ", i);
        scanf("%d", &a[i]);
    }
}
void XuatMang(int *a, int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d", a[i]);
    }
}
int main(){
    int n;
    // Nhập số phần tử của mảng và kiểm tra tính hợp lệ
    do {
        printf("\nNhap so luong phan tu cua mang: ");
        scanf( "%d",&n );
 
        if (n <=0){
            printf( "Vui long nhap lai so luong phan tu ." );
        }
    } while (n <=0);// điều kiện dừng lại vòng lap nay la khi ta nhap mot so n lớn hơn 0 thì nó sẽ vi phạm vòng lặp 
 
    // Khai báo con trỏ và cấp phát bộ nhớ
    int *a = (int *)malloc(n * sizeof(int *));
 
    // Nhập
    NhapMang( a, n );
 
    // Xuất
    printf( "\nMang vua nhap la: " );
    XuatMang( a, n );
}
 