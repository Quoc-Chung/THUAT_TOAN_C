#include<stdio.h>
#include<math.h>
// voi nhung dang bai nhu nay thi ta dat tong la so dau truoc ,
// sau do duyet mot vong for 
// tim ra cong thuc tong quat cua bieu thuc va tinh (thuong cong thuc o cuoi )
void nhap(float a[],int n){
	for(int i=1;i<=n;i++){
		scanf("%f",&a[i]);
	}
}
void in(float a[],int n){
	printf("\nMang vua nhap :\n");
	for (int i=1;i<=n;i++){
		printf("%.2f ",a[i]);
	}
}
void congthuc (float  a[],int n){
   float s=2021;
   for (int i=1;i<=n;i++){
    s+=pow(-1,i+1)*pow(a[i],i);
   }
   printf("\n%.2f ",s);

}
void tong(float a[],int n){
	float s=2022;
	for(int i=1; i<=n;i++){
		s+=pow(a[i],i)*pow(-1, i+1);
	}
	printf("\ntong la :%.2f",s);
}

int main()
{
	int n;
	printf("Nhap n:");
	scanf("%d",&n);
	float a[n];
	nhap(a,n);
	in(a,n);
	//tong(a,n);
	congthuc(a,n);
	return 0;
}
