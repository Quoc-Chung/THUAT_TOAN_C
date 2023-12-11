#include <stdio.h>
#include <math.h>
void nhapmang(int a[],int n){
for (int i=1;i<=n;i++){
scanf("%d",&a[i]);
}
}
void inmang(int a[],int n){
  printf("\nMang la :\n");
for (int i=1;i<=n;i++){
printf("%d ",a[i]);
}
} 
void kiemtraxuathien(int a[],int n,float x){
	int flag=0;
	for (int i=1;i<=n;i++){
		if((float)a[i]==x){
			flag++;
		}
	}
	if(flag==0){
		printf("\nSo x khong xuat hien trong mang.");
	}
	else {
		printf("\nSo x xuat hien %d lan trong mang.",flag);	
	}
}
void tong(int a[],int n){
 float tong =0;
for (int i=1;i<=n;i++){
       a[i]=(float)a[i];
       a[i+1]=(float)a[i+1];
    tong+=(a[i]+a[i+1])/(a[i]-a[i+1]);
      }
      printf("\nTong can tim la :%.2f",tong);
}
int main (){
	int n,a[100];
	float x;
	printf("Nhap n:");
	scanf("%d",&n);
	printf("\nNhap x:");
	scanf("%f",&x);
	nhapmang(a,n);
	inmang(a,n);
	kiemtraxuathien(a,n,x);
	tong(a,n);
	
	
}
