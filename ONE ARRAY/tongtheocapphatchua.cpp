#include <stdio.h>
#include <stdlib.h> // Thư viện này để cấp phát bộ nhớ động

int main()
{
    int n, i, *ptr, sum = 0;
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);
    ptr = (int *)calloc(n, sizeof(int));
 
    // Nếu không thể cấp phát, 
    // hàm malloc sẽ trả về con trỏ NULL
    if (ptr == NULL)
    {
        printf("Co loi! khong the cap phat bo nho.");
        exit(0);
    }
    for (i = 0; i < n; ++i)
    {
        printf("Nhap gia tri %d: ", i+1); 
        scanf("%d", ptr + i);
        printf("\n"); 
        sum += *(ptr + i);
    }
    printf("Tong = %d \n", sum);

    printf("Them phan tu: ");
    int m;
    scanf("%d", &m);
    ptr = (int*)realloc(ptr, m* sizeof(int));
    for (i = n; i < n+m; ++i)
    {
        printf("Nhap gia tri %d: ", i+1); 
        scanf("%d", ptr + i);
        printf("\n"); 
        sum += *(ptr + i);
    }

    printf("Tong moi = %d", sum);
    // Giải phóng vùng nhớ cho con trỏ
    free(ptr);
    return 0;
}