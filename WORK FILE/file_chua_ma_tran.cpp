#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define MAX 100
void nhapmang(int a[][MAX],int &m,int &n){
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			printf("Nhap gia tri a[%d][%d]:",i,j);
			scanf("%d",&a[i][j]);
		}
	}
}
void inmang (int a[][MAX],int m,int n){
	printf("\nMa tran truyen tu file vao la:\n");
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			
		printf("%d ",a[i][j]);
	}
	printf("\n");
  }
}
void trungbinhcong(int a[][MAX],int m,int n){
	int dem=0;
	float s=0;
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			if(a[i][j]>0){
				s+=a[i][j];
				dem++;
			}
		}
	}
	printf("\nGia tri trung binh cong la :%.2f",s/dem);
}
// duyt tung cot mot ,xem cot nao 
// dùng kết quả đã nhập sẵn trong file  để truy suất các kết quả 
void tongtungcot(int a[][MAX],int m,int n){
	int tong;
	printf("\n");
	for (int j=0;j<n;j++){
		tong=0;
		for (int i=0;i<m;i++){
			tong+=a[i][j];
		}
		printf("%d ",tong);
	}
}
void doc_ket_qua_truyen_vao_bai(int a[][MAX],int &m,int &n,char duong_dan[]){
	FILE *f;
	f = fopen(duong_dan,"r");// repair "w" to "r" on file write
	// check file open 
	if(f==NULL){
		printf("\nKhong the truy suat file ket qua .");
		exit(1);
	}
	// đọc kích thước của mảng 
	fscanf(f," %d ",&m);
	fscanf(f," %d ",&n);
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			fscanf(f," %d ",&a[i][j]);
		}
	}
	fclose(f);// close file 
}
void ghi_ket_qua_vao_file (int a[][MAX],int m,int n,char duong_dan[]){
	FILE *f;
	f=fopen(duong_dan,"w");// open file 
	// check file open 
	if(f==NULL){
		printf("\nFile khong mo duoc.");
		exit(1);
	}
	fprintf(f," %d ",m);
	fprintf(f," %d ",n);
	fprintf(f,"\n");
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			fprintf(f," %d ",a[i][j]);
		}
		fprintf(f,"\n");
	}
	fclose(f);// close file  
}
int main (){
	int m,n;
	char duong_dan[100]="C:\\Users\\Admin\\Documents\\THUATTOANC\\WORD FILEC\\matran.txt";
	char duong_dan1[100]="C:\\Users\\Admin\\Documents\\THUATTOANC\\WORD FILEC\\matran1.txt";
//	printf("Nhap kich thuoc :");
//	scanf("%d%d",&m,&n);
	int a[100][100];// ma trận này chứa kết quả nhập vào trrong compile
	
//	nhapmang(a,m,n);//==>ta sẽ dùng file chứa kết quẩ chứ không cần dùng hàm  nhap nua 
    doc_ket_qua_truyen_vao_bai(a,m,n,duong_dan1);
	inmang(a,m,n);
	//ghi_ket_qua_vao_file (a,m,n,duong_dan);
	trungbinhcong(a,m,n);
	tongtungcot (a,m,n);
	return 0;
}

