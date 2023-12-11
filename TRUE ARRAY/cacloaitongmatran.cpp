#include <stdio.h>
#include <math.h>
void nhapmang (int a[100][100],int m,int n){
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			scanf("%d",&a[i][j]);
		}
	}
}
void inmang(int a[100][100],int m,int n){
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			printf("%d",a[i][j]);
		}
	}
}
int swap(int a,int b){
for (int i=0;i<m;i++){
	int sapxep =a;
	a=b;
	b=sapxep;
}
return sapxep;
}

	
int tongcachang (int a[100][100],int m,int n){
	for(int i=0;i<m;i++){//duyet het mot hang 
	int tong=0;
	for (int j=0;j<n;j++){
		tong +=a[i][j];
	}
	}
  printf("Tong cac hang :%d\n",tong);
}
int  tongcaccot(int a[100][100],int m,int n){
	for (int j=0;j<n;j++){
		int tong1=0;
		for (int i=0;i<m;i++){
			tong1+=a[i][j];
		}
	}
	printf("\nTong cac cot :%d\n",tong1);
}
int tongcotbatki(int a[100][100],int x,int m,int n){
	int tong2=0;
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			tong2 +=a[i][x];
			
		}
	}
	return tong2;
}
int tongduongcheo (int a[100][100],int m,int n){
	int cheo=0;
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			if(i==j){
				cheo+=a[i][j];
			}
		}
	}
	return cheo;
}
int main (){
	
	int m,n;
	printf("Kich thuoc:\n");
	scanf("%d%d",&m,&n);
	int a[100][100];
	nhapmang(a,m,n);
	printf("\nIn mang :\n");
	tongcachang(a,m,n);
   tongcaccot(a,m,n);
 
	printf("\nNhap cot bat ki :\n");
	int x;
	scanf("%d",&x);
    printf("Tong cot bat ki :%d",tongcotbatki(a,x,m,n));

	printf("\nTong duong cheo :%d",tongduongcheo(a,m,n));
	
	return 0;
}