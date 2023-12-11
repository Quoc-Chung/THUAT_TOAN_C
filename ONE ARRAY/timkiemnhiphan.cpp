#include <stdio.h>
#include <math.h>
void nhapmang(int a[],int n){
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
}
void inmang(int a[],int n){
	printf("\nMang in ra la :\n");
	for (int i=1;i<=n;i++){
		printf("%d ",a[i]);
	}
}
int timkiemnhiphan(int a[],int n,int x){
	int dau=1;
	int cuoi=n;
	int giua;
	while (dau<=cuoi){
	   giua=(dau+cuoi)/2;
	    if(x==a[giua]){
	    	return giua;
		}
		else if(x>a[giua]){// dung else if vi lam the no moi thay doi duoc gia tri dau va cuoi 
			dau=giua+1;
		}
		else if(x<a[giua]){
			cuoi=giua-1;
		}	
			         }
	return -1;
}
void kiemtra(int a[],int n,int x){
	int vitri=timkiemnhiphan(a,n,x);
	if(vitri==-1){
		printf("\nKhong co gia tri nao bang x");
	}
	else{
		printf("\nTon tai mot so bang x trong mang tai vitri %d.",vitri);
	}
}
int main (){
	int n;
	printf("Nhap n:");
	scanf("%d",&n);
	int a[n];
	nhapmang(a,n);
	inmang(a,n);
	int x;
	printf("\nNhap x:");
	scanf("%d",&x);
	kiemtra(a,n,x);
	return 0;
}