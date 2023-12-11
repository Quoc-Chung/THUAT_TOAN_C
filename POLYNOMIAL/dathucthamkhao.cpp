//Đa thức

//a. Nhập bậc n và các hệ số a0,a1,...,an của đa thức P(x)
//b. Nhập x,y là hai số thực tính căn(P(x)-P(y))
//c. Tính các hệ số của đa thức (2x-1)*P(x)
#include<stdio.h>
#include<conio.h>
#include<math.h>
int main(){
int n;
float x,y,p,q,s,a[100],b[100];

printf("Nhap bac cua da thuc n = ");
scanf("%d",&n);

for(int i=0;i<=n;i++)
{
printf("a[%d] = ",i);
scanf("%f",&a[i]);
}

printf("\nCac he so cua da thuc \n");
for(int i=0;i<=n;i++)
printf("%8.2f",a[i]);

printf("\nNhap x = "); scanf("%f",&x);
printf("\nNhap y = "); scanf("%f",&y);

p=1;
q=1;
s=0;

for(int i=1;i<=n;i++)
{
p=p*x;
q=q*y;
s=s+a[i]*(p-q);
}

if(s>=0) printf("\nGia tri can tinh la %f",s);
else printf("\nKhong tinh duoc gia tri");
//Tinh cau c
b[0]=-a[0];
b[n+1]=2*a[n];
for(int i=1;i<=n;i++)
b[i]=2*a[i-1]-a[i];

printf("\nCac he so cua da thuc (2x-1)*P(x)\n");
for(int i=0;i<=n+1;i++)
printf("%8.2f",b[i]);

getch();
return 0;
}