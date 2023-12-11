#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100
void delete_newline(char c[]){
	size_t len = strlen (c);
	if(c[len-1]=='\n'){
		c[len-1]='\0';
	}
}
struct dang_vien{
	int so_dang_vien;
	char  hoten[30];
	int namsinh;
	int nam_ket_nap;
};
typedef struct dang_vien DANGVIEN;
void nhap_1_dang_vien(DANGVIEN &dv){
	printf("\nNhap ho ten:");
	fflush(stdin);
	fgets(dv.hoten,sizeof(dv.hoten),stdin);
	printf("\nNhap nam sinh :");
	scanf("%d",&dv.namsinh);
	printf("\nNhap nam ket nap :");
	scanf("%d",&dv.nam_ket_nap);
}
void nhap_nhieu_dang_vien (DANGVIEN dv[],int &n){
	printf("\nNhap so luong dang vien:");
	scanf("%d",&n);
	for (int i=0;i<n;i++){
		nhap_1_dang_vien(dv[i]);
	}
}
void in_dang_bang1(DANGVIEN dv[], int n) {
    printf("\n\t\tBANG THONG TIN\n\n");
    printf("+----------------------+-----------+------------+\n");
    printf("| %-20s | %-9s | %-10s|\n", "Ho va ten", "Nam sinh","Nam ket nap");
    printf("+----------------------+-----------+------------+\n");
    for (int i = 0; i < n; i++) {
        delete_newline(dv[i].hoten);
        printf("| %-20s | %-9d | %-10d |\n", dv[i].hoten, dv[i].namsinh, dv[i].nam_ket_nap);
    }
    printf("+----------------------+-----------+------------+\n");
}
void ghi_dang_vien_vao_file(DANGVIEN dv[],int n){
	char  duong_dan[100]="C:\\Users\\Admin\\Documents\\THUATTOANC\\WORD FILEC\\ket_qua_2_de3.bin";
	FILE *f;
	f=fopen(duong_dan,"wb");// file để đọc file nhị phân 
	if(f==NULL){
		printf("\nKhong ghi duoc ket qua vao file");
		exit(1);
	}
	fwrite(&n,sizeof(n),1,f);// ghi so luong dang vien vao file(chỉ nhập một số n)
	for (int i=0;i<n;i++){
		fwrite(&dv[i],sizeof(DANGVIEN),1,f); // mỗi lần chỉ ghi một đảng viên 
	}
	// đóng file
	fclose (f);
}
// phải luôn nhớ file đọc luôn phải truyền tham chiếu 
void doc_file_tu_van_ban(DANGVIEN dv[],int &n){
	char duong_dan[100]="C:\\Users\\Admin\\Documents\\THUATTOANC\\WORD FILEC\\ket_qua_2_de3.bin";
	FILE *f;
	f=fopen(duong_dan,"rb");// file này để đọc 
	if(f==NULL){
		printf("\nKhong the mo file de doc.");
		exit(1);
	}
	// dọc số lượng đảng viên 
	fread(&n,sizeof(n),1,f);
	// dọc noi dung
	for  (int i=0;i<n;i++){
		fread(&dv[i],sizeof(DANGVIEN),1,f);
	}
	// đóng file
	fclose(f);	
}
void swap (DANGVIEN *a,DANGVIEN *b){
	DANGVIEN tam=*a;
	*a=*b;
	*b=tam;
}
void sap_xep_dang_vien(DANGVIEN dv[],int &n){
	for (int i=0;i<n-1;i++){
		for (int j=i+1;j<n;j++){
			if(dv[i].nam_ket_nap >dv[j].nam_ket_nap){
				swap(&dv[i],&dv[j]);
			}
		}
	}
	printf("+------------------------+\n");
	printf("|%-5s|%-15s   |\n","STT","BANG SAP XEP");
	printf("+------------------------|\n");
	for (int i=0;i<n;i++){
		delete_newline(dv[i].hoten);
    printf("|%-5d|%-15s   |\n",i+1,dv[i].hoten);
	}
	printf("+------------------------+\n");
}
// mỗi dòng phải có \n và \n xếp sau |
void thongke(DANGVIEN dv[],int &n){
	printf("+------------------------------+\n");
	printf("|     DANH SACH THOA MAN       |\n");
	printf("+------------------------------+\n");
	for (int i=0;i<n;i++){
		if(2023-dv[i].nam_ket_nap>=20){
			delete_newline(dv[i].hoten);
	printf("|   %-25s  |\n",dv[i].hoten);
		}
	}
	printf("+------------------------------+\n");
}
//int main (){
//	int n;
//	DANGVIEN dv[MAX];
//	nhap_nhieu_dang_vien (dv,n);
//	in_dang_bang1(dv,n);
//	ghi_dang_vien_vao_file (dv,n);
//	
//	return 0;
//}
int main (){
	int n;
	DANGVIEN dv[MAX];
	doc_file_tu_van_ban(dv,n);
	in_dang_bang1(dv,n);
	sap_xep_dang_vien(dv,n);
	thongke(dv,n);
}