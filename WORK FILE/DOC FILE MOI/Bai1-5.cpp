#include<stdio.h>
#include<math.h>
#include<stdlib.h>
void DocFile(float ***a,int &m,int &n,char *tentep){
	FILE *f;
	f=fopen(tentep,"r");
	if(f==NULL){
		printf("\nKhong the mo duoc file.");
		exit(0);
	}
	fscanf(f,"%d%d",&m,&n);
	// cấp phát hàng  một con trỏ cấp 1 trỏ đến 
	*a=(float **)malloc(m*sizeof(float*));
	for(int i=0;i<m;i++){
		(*a)[i]=(float*) malloc(n*sizeof(float));
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			fscanf(f,"%f",&((*a)[i][j]));
		}
	}
	printf("\nMA tran in ra  man hinh la  :");
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
		printf("%.2f ",(*a)[i][j]);
		}
		printf("\n");
	}		
}
void InFile(float **a,int m,int n){
	printf("\nMa tran va in ra la :\n");
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			printf("%.2f ",a[i][j]);
		}
		printf("\n");
	}
}
void TichTungHAng(float **a,int m,int n){
	// duyet qua tung  hang 
	printf("\nTich tung hang  la :\n"); 
	float max=-1e8;
	for(int i=0;i<m;i++){
		float tich=1;
		for(int j=0;j<n;j++){
			tich*=a[i][j];
			if(max<tich){
				max=tich;
			}
		}
		printf("\nHang %d:%.2f",i,tich);
	}
	printf("\nGia tri tich tung hang:%.2f",max);
}
void DemPhanTuDDuong(float **a,int m,int n){
	int dem=0;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(a[i][j]>0){
				dem++;
			}
		}
	}
	printf("\nSo phan tu duong ma tran la :%d",dem);
}
int main(){
	int m,n;
	float **a;
	char tentep[100];
	printf("\nNhap ten tep:");
	gets(tentep);
	DocFile(&a,m,n,tentep);
	InFile(a,m,n);
	TichTungHAng(a,m,n);
	return 0;
}