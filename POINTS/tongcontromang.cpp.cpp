#include<stdio.h>
#include<conio.h>

int main() {
   int a[10];
   int i, sum = 0;
   int *ptr;// tao bien con tro
   printf("\nNhap 10 phan tu: ");
 
   for (i = 0; i < 10; i++)
      scanf("%d", &a[i]);// khai bao lan luot cac gia tri cua mang bang vong for
 
   ptr = a; //tro con tro cua mang den dia chi cua mang a;
 
   for (i = 0; i < 10; i++) {
      sum = sum + *ptr;// dùng giá tri tro den dia chi de chay
      ptr++;
   }
 
   printf("Tong cac phan tu cua mang la: %d", sum);
   return(0);
}
