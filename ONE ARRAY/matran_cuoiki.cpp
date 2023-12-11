#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#define MAX 100
void nhap(int a[][MAX],int &m,int &n){
	printf("\nNhap kich thuoc:");
	scanf("%d%d",&m,&n);
	for (int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			printf("\nNhap a[%d][%d]:",i,j);
			scanf("%d",&a[i][j]);
		}
	}
}
void in(int a[MAX][MAX],int m,int n){
	printf("\nMa tran vua duoc truy xuat la :\n");
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			printf("%d  ",a[i][j]);
		}
		printf("\n");
	}
}
void max_tamgiacduoi_mincheophu(int a[][MAX],int m,int n){
	int max=INT_MIN;
	int min_phu=INT_MAX;
	int flag=0;
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			if(max<a[i][j]){
				max=a[i][j];
			}
			if(i>j && a[i][j]!=0){
				flag++;
			}
			if((i==n-1-j || j==n-1-i) && min_phu>a[i][j]){
				min_phu=a[i][j];
			}
		}
	}
	printf("\nGia tri lon nhat m tran la :%d",max);
	if(flag==0){
		printf("\nMa tran la ma tran tam giac duoi");
	}
	else {
		printf("\nMa tran la ma tran tam giac duoi .");
	}
	printf("\nGia tri min cua ma tran cheo phu:%d",min_phu);
}
void in_ket_qua_vao_file(int a[][MAX],int m,int n,char duong_dan[]){
	nhap(a,m,n);// nhập file trước rồi sau đó mới làm 
	// initial file
	FILE *f;
	f=fopen(duong_dan,"w");// file này để ghi vào file
	// check file open 
	if(f==NULL){
		printf("\nKhoong viết được vào file");
		exit(1);
	}
	// viết kích thước vào file  
	fprintf(f," %d ",m);
	fprintf(f," %d\n",n);
	for (int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			fprintf(f, " %d ",a[i][j]);
		}
		fprintf(f,"\n");
	}
	// close file
	fclose (f);
}
void lay_ket_qua_tu_file_ra(int a[][MAX],int &m,int &n,char duong_dan[]){
	FILE *f;
	f=fopen (duong_dan,"r");
	// check file open
	if(f==NULL){
		printf("\nFile khong truy xuat duoc ma tran de dung");
		exit(1);
	}
	// đọc kích thước để dùng 
	fscanf(f,"%d",&m);
	fscanf(f,"%d",&n);
	// read test used it
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			fscanf(f,"%d",&a[i][j]);
		}
	}
	// close file
	fclose (f);
}
int main(){
	int m,n;
	char duong_dan[100]="C:\\Users\\Admin\\Documents\\THUATTOANC\\WORD FILEC\\output.txt";// phải có đuôi mới chay đúng được
	int a[MAX][MAX];
	lay_ket_qua_tu_file_ra(a,m,n,duong_dan);
	//in_ket_qua_vao_file(a,m,n,duong_dan);
	in(a,m,n);
	max_tamgiacduoi_mincheophu(a,m,n);
	return 0;
}