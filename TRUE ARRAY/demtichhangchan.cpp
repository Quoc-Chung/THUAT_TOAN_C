#include <stdio.h>
#include <math.h>
void  nhapmang(int a[100][100],int m,int n){
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			printf("Nhap mang a[%d][%d]:",i,j);
		 scanf("%d",&a[i][j]);	
		}
	}
}
void inmang(int  a[100][100],int m,int n){
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			printf("%d  ",a[i][j]);
		}
		printf("\n");
	}
}
// no se  bao gom hai dong dau va hai dong ben canh 3*3
//            0        1       2
//    0    a[0][0] a[0][1] a[0][2]

//    1    a[1][0] a[1][1] a[1][2]

//    2    a[2][0] a[2][1] a[2][2]
// tich so hang chan la  thi ta phai chay tung hang mot va cac sau do chay tu cot dau toi cot cuoi cua tung hang 
int  demsohangchan (int a[100][100],int m,int n){
	  int dem=0;	
	for (int i=0;i<m;i++){
		int tich=1;
		for (int j=0;j<n;j++){
			tich *=a[i][j];
		
		}
		if(tich % 2== 0){
			dem++;
		}
	}
	return dem ;
	
}
int main(){
	int m,n;
	printf("Nhap kich thuoc:\n");
	scanf("%d %d",&m,&n);
	int  a[100][100];
	printf("Nhap mang:\n");
	nhapmang(a,m,n);
	printf("\nIn mang hai chieu la :\n");
	inmang (a,m,n);
	printf("So luong hang co tich chan la :%d",demsohangchan(a,m,n));
}