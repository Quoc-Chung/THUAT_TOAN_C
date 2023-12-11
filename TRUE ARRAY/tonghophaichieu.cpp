#include <stdio.h>
#include <math.h>
void  nhapmang(float a[100][100],int m,int n){
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			printf("Nhap mang a[%d][%d]:",i,j);
		 scanf("%f",&a[i][j]);	
		}
	}
}
void inmang(float a[100][100],int m,int n){
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			printf("%.2f ",a[i][j]);
		}
		printf("\n");
	}
}
 void tongduong(float a[100][100],int m,int n){
	float sum1=0;
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			if(a[i][j]>0)
				sum1=sum1+a[i][j];
		}
	}
  printf("Tong duong la :%.2f",sum1);
}
void  tinhtongcachang(float a[100][100],int m,int n){
	for (int i=0;i<m;i++){
		float sum=0;
		for (int j=0;j<n;j++){
			sum +=a[i][j];
		}
		printf("Tong cac hang :%.2f\n",sum);
	}
}

void kiemtra(float a[100][100],int m,int n){
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			if(a[i][j]<0){
				a[i][j]*=(-1);
			}
		}
	}
}
int hoanthien(int x){
	int tong=0;
	for (int i=1;i<=x/2;i++){
		if (x%i==0){
			tong +=i;
		}
	}
	if(tong == x){
		return 1 ;
		
	}
	else {
		return 0 ;
	}
}
float  tonghoanthienmang(float a[100][100],int m,int n){
	int tong =0;
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			if (hoanthien(a[i][j]) == 1){
				tong+=a[i][j];
			}
		}
	}
	return tong ;
}

// no se  bao gom hai dong dau va hai dong ben canh 3*3
//            0        1       2
//    0    a[0][0] a[0][1] a[0][2]

//    1    a[1][0] a[1][1] a[1][2]

//    2    a[2][0] a[2][1] a[2][2]
//
float tinhtongbien (float a[100][100],int m,int n){
	float tong = 0;
	//tinh tong dong dau va dong cuoi
	for (int j=0;j<n;j++){
		tong+=a[0][j]+a[m-1][j];
	}
	//tinh tong hai dong ben canh 
	for (int i=0;i<=m;i++){
		tong+=a[i][0]+a[i][n-1];
	}
	return tong;
}

int main(){
	int m,n;
	printf("Nhap kich thuoc:\n");
	scanf("%d %d",&m,&n);
	float a[100][100];
	printf("Nhap mang:\n");
	nhapmang(a,m,n);
	printf("\nIn mang hai chieu la :\n");
	inmang (a,m,n);
	tinhtongcachang(a,m,n);
   tongduong(a,m,n);
	printf("\nBien doi ve ma tran duong :\n");
	 for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			 kiemtra (a,m,n);
			printf("%.2f ",a[i][j]);
		}
		printf("\n");
	}
	printf("\nTong hoan thien mang la :%.2f",tonghoanthienmang (a,m,n));
	printf("\nTong bien mang : %.2f",tinhtongbien(a,m,n));
}




