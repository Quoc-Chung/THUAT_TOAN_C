#include <stdio.h>
#include <math.h>
void nhapday(int a[],int n){
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
}
void inday(int a[],int n){
	printf("Day vua nhap la:\n");
	for (int i=1;i<=n;i++){
		printf("%d ",a[i]);
	}
}
void kiemtraday(int a[],int n){
	int flag=0;
	for (int i=1;i<n;i++){// so di chi chay den i<n vi mih cong them
		if(a[i]<=a[i+1]){
			flag=1;
		}
		if(a[i]>a[i+1]){
			flag=2;
			break;
		}
	}
	if(flag==1){
		printf("\nDay don dieu khong giam");
	}
	if(flag==2){
		printf("\nDay khong thoa man ");
	}
}
void indaydaonguoc(int a[],int n){
	printf("\nDay so dao nguoc la :\n");
	for (int i=n;i>=1;i--){
		printf("%d ",a[i]);
	}
}
int main(){
	int n;
	printf("Nhap n:");
	scanf("%d",&n);
	int a[n];
	nhapday(a,n);
	inday(a,n);
	kiemtraday(a,n);
	indaydaonguoc(a,n);
	return 0;
}