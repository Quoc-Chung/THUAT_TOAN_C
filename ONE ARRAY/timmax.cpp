#include <stdio.h>
#include <math.h>
int main (){
int n;
printf("Nhap n:");
scanf("%d",&n);
int a[n];
int max=-1000;
printf("Nhap mang:");
for(int i=1;i<=n;i++){
printf("Nhap a[%d]:",i);
scanf("%d",&a[i]);
}
for(int i=1;i<=n;i++){
for(int j=n;j>=1;j--){    
if(max<(a[i]/j))
max=a[i]/j;
}
}
printf("Max la :%d",max);
}
    