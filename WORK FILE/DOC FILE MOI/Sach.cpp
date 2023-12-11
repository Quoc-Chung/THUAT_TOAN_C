//Bài 2-2 Nhập danh sách n đầu sách từ tệp input.txt. Mỗi đầu sách là một cấu trúc được lưu
//trữ trên 3 dòng của tệp gồm TenSach (Tên sách), NhaXB (Nhà xuất bản) và Gia (Giá
//thành). Dòng đầu tệp là số tự nhiên n lưu trữ số sách. Yêu cầu:
//1. Đếm xem có bao nhiêu cuốn sách của nhà xuất bản cho trước được nhập từ bàn phím.
//2. In ra màn hình các đầu sách theo thứ tự giảm dần của giá, thông tin mỗi đầu sách được
//in trên một dòng.
//3. Kết quả lưu vào tệp output.txt bao gồm cả các thông tin về n đầu sách
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
struct  Sach{
	char TenSach[50];
	char NhaXuatBan[50];
	int giaThanh;
};
void DocFile(Sach **s, int &n, char *tentep) {
    FILE *f;
    f = fopen(tentep, "r");
    if (f == NULL) {
        printf("\nKhong the mo duoc file.");
        exit(0);
    }
    fscanf(f, "%d", &n);
    *s = (Sach *)malloc(n * sizeof(Sach));
    for(int  i=0;i<n;i++){
        fscanf(f," %[^\n]",(*s)[i].TenSach);
		fscanf(f," %[^\n]",(*s)[i].NhaXuatBan);
		fscanf(f,"%d",&(*s)[i].giaThanh); 
	}
    fclose(f);
}
void InFile(Sach *s,int n){
	printf("\nNoi dung trong  van ban la :\n");
	for(int i=0;i<n;i++){
		printf("\nSach thu %d:\n",i+1);
		printf("\nTen Sach :%s\n",s[i].TenSach);
		printf("\nNha xuat ban :%s\n",s[i].NhaXuatBan);
		printf("\nGia thanh :%d\n",s[i].giaThanh);
	}
}
void XapXepSach(Sach *s,int  n){
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n;j++){
		if(s[i].giaThanh >s[j].giaThanh){
			int tam =s[i].giaThanh;
			s[i].giaThanh= s[j].giaThanh;
			s[j].giaThanh=tam;
		}
	}
  }
	printf("\nDanh sach xep theo bien ");
	for(int i=0;i<n;i++){
		printf("\nTen Sach :%s\n",s[i].TenSach);
	}
}
void demSachxuatBan(Sach *s,int n, char NhaXB[]){
	int dem1=0;
	for(int i=0;i<n;i++){
	   if(strcmp(s[i].NhaXuatBan,NhaXB)==0){
	   	dem1++;
	   }
	}
	printf("\nSo sach cua nha xuat ban %s la %d",NhaXB,dem1);
}
int main(){
	int  n;
	Sach *s;
	char tentep[50]="Sach.txt";
	DocFile(&s,n,tentep);
	InFile(s,n);
	XapXepSach(s,n);
	char NhaXB[50];
	gets(NhaXB);
	demSachxuatBan(s,n,NhaXB);
	return 0;
}