#include <stdio.h>
#include <math.h>
int main (){
int n;
printf("Nhap so n:\n");
scanf("%d",&n);
int c=n%10;
printf("Chu so cuoi cung la :%d",c); 
int sodao=0;
int dem =0;
while (n>0){
	
sodao=sodao*10+n%10;
n=n/10;
dem++;
}
int d=sodao%10;
printf("\nChu so dau trong mang:%d",d);
printf("\nSo luong chu so trong mang la:%d",dem);
printf("\nSo nguoc la :%d",sodao);
}

