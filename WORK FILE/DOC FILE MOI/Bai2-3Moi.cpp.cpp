//Bài 2-3 Nhập danh sách n dầu sách từ tệp input.txt. Mỗi đầu sách là một cấu trúc được lưu 
//trữ trên ba dòng của tệp gồm TenSach (Tên sách), NamXB (Năm xuất bản) và Gia (Giá 
//thành). Dòng đầu tệp là số tự nhiên n lưu trữ số sách. Yêu cầu: 
//1. Tìm kiếm sách theo tên sách được nhập từ bàn phím. 
//2. Tính trung bình cộng giá thành các cuốn sách được xuất bản trong khoảng thời gian từ 
//năm 2011 đến năm 2013, 
//3. Kết quả lưu vào tệp output.txt bao gồm cả các thông tin về n đầu sách
#include<bits/stdc++.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
struct  Sach{
	char TenSach[50];
	int nam;
	float gia;
};
void DocFile (Sach **s,int &n,char *tentep){
	FILE *f;
	f=fopen(tentep,"r");
	if(f==NULL){
		printf("\nKhong the doc duoc file.");
		exit(0);
	}
	fscanf(f,"%d",&n);
	*s=(Sach*) malloc (n*sizeof(Sach));
	for(int i=0;i<n;i++){
		fscanf(f," %[^\n]",(*s)[i].TenSach);
		fscanf(f,"%d",&(*s)[i].nam);
		fscanf(f,"%f",&(*s)[i].gia);
	}
	fclose(f);
}
void InFile(Sach *s, int n,FILE *f=stdout) {
	fprintf(f,"Sach duoc doc tu file la\n");
	for (int i = 0; i < n; i++) {
		fprintf(f,"\nTen Sach :%s--Nam xuat ban:%d--Gia thanh :%.3f dong\n", s[i].TenSach,s[i].nam,s[i].gia);
	}
}
void TimKiemSach(Sach *s, int n,FILE *f=stdout) {
	char TenKiem[50];
	printf("\nNhap ten sach can kiem:");
	gets(TenKiem);
	int flag = 0;
	for (int i = 0; i < n; i++) {
		if (strcmp(s[i].TenSach, TenKiem) == 0) {
			fprintf(f,"\n-------Sach duoc tim thay ------\n");
			fprintf(f,"\nTen Sach :%s", s[i].TenSach);
			fprintf(f,"\nNam xuat ban:%d", s[i].nam);
			fprintf(f,"\nGia thanh :%.3f dong.", s[i].gia);
			flag = 1;
			break;
		}
	}
	if (flag == 0) {
	fprintf(f,"\nSach vua nhap khong duoc tim thay.");
	}
}
void TrungBinhCong(Sach *s,int n,FILE *f=stdout){
	int dem=0;
	float tong=0;
	for (int i=0;i<n;i++){
		if(s[i].nam >= 2011 && s[i].nam<2013){
			dem++;
			tong+=s[i].gia;
		}
	}
	fprintf(f,"\nTB gia cua cac cuon sach  tu nam  2011 -2013:%.3f\n",tong/dem);
}

int  main(){
	int n;
	Sach *s;
	char tentep[40]="Bai2-3.txt";
	DocFile (&s,n,tentep);
	FILE *f=fopen("invaodaynay.txt","w");
	InFile(s,n,f);
	TrungBinhCong(s,n,f);
 	TimKiemSach(s,n,f);
 	fclose(f);
	return 0;
}
