#include <stdio.h>
#include <math.h>
void nhapmang (int a[100][100],int m,int n){
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			printf("Nhap a[%d][%d]:",i,j);
			scanf("%d",&a[i][j]);
		}
	}
}
void inmang (int a[100][100],int m,int n){
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
}void trungbinhcong(int a[100][100],int m,int n ){
	int dem=0;
	int tong=0;
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			if(a[i][j]%2==0 && a[i][j]<=100){
				tong+=a[i][j];
				dem++;
			}
		}
	}
	float s=(float)tong/dem;
	printf("\nTrung bnh cong la %.2f",s);
}
void timmintungcot (int a[100][100],int m,int n){
	int min=a[0][0];// cho min la so dau tien cua mma tran
	int j=0;// cho cot bang 0;
	while (j<n){// chay mot vong while cho den khij lon hon so cot n thi dung vong lap
		min=a[0][j];// trong vong for thi ta dat so dau tien cua tung cot laa so nhu nhat 
		for (int i=0;i<m;i++){// duyet tu hang 1 den hang cuoi tim do nho nhat 
			if(min>a[i][j]){
				min=a[i][j];
			}
		}
		printf("\n%d\n",min);// het 1 vong for thi ta se in ra mot so min roi chuyen sang tim  cot khac bang cach tang j++
		j++;
	}
}
// phai tim ra mot cach khac chi can dung vong for 
void timmintungcot1(int a[100][100],int m,int n){
	int min;// dat mot bien min 
	for (int j=0;j<n;j++){// duyet mot vong for tung hang mot 
		min=a[0][j];// dat min bang so dau tien tung cot 
		for (int i=0;i<m;i++){// duyet mot vong for tu cot 1 den cot cuoi cung tim min 
			if(min>a[i][j]){
				min=a[i][j];
			}
		}
		printf("\n%d\n",min);// het vong for thi in ra so min vua timm duoc vaf chuyen cot tim tiep 
	}
}
int main (){
	int m,n;
	printf("Ma tran cap :");
	scanf("%d%d",&m,&n);
	int a[100][100];
	nhapmang(a,m,n);
	printf("Ma tran la :\n");
	inmang(a,m,n);
	trungbinhcong(a,m,n);
	timmintungcot1(a,m,n);
	return 0;
	
}
