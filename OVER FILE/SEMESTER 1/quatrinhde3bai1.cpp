//Định nghĩa một cấu trúc Sinh viên gồm các thành phần: Mã SV, tên SV, điểm, 
//trường (giả sử có 3 trường là 1, 2, 3). Nhập, xuất n sinh viên.
// Thống kê tổng số điểm của từng trường, cho biết trường nào có điểm cao nhất.
//Nhập vào tên sinh viên, in ra màn hình thông tin của sinh viên đó.
// Tìm sinh viên có điểm cao nhất
#include <stdio.h>
#include <math.h>
#include <string.h>
struct sinhvien {
	int maSV;
	char ten[30];
	float diem ;
    int truong;
};
void nhap(struct sinhvien sv[],int n){
	for (int i=1;i<=n;i++){
		printf("Nhap sinh vien thu %d :\n",i);
		printf("\nNhap ten sinh vien :");
		 fflush(stdin); 
		 fgets(sv[i].ten, sizeof(sv[i].ten), stdin);
		 printf("\nNhap ma sinh vien :");
		 scanf("%d",&sv[i].maSV);
		 printf("\nNhap diem :");
		 scanf("%f",&sv[i].diem);
		 printf("\nNhap ten truong :");
		 scanf("%d",&sv[i].truong);
	}
}
void in(struct sinhvien sv[],int n){
	for (int i=1;i<=n;i++){
		printf("Sinh vien thu :%d",i);
		printf("\nTen sinh vien la :%s",sv[i].ten);
		printf("\nMa sinh vien la :%d",sv[i].maSV);
		printf("\nDiem la:%.2f",sv[i].diem);
		printf("\nTen truong la :%d",sv[i].truong);
	}
}
// Thống kê tổng số điểm của từng trường, cho biết trường nào có điểm cao nhất.
//
void diemtungtruong(struct sinhvien sv[],int n){
	float diem1=0 ;
	float diem2=0;
	float diem3=0;
	for (int i=1;i<=n;i++){
		if(sv[i].truong==1){
		diem1+=sv[i].diem ;
	}
	if (sv[i].truong==2){
		diem2+=sv[i].diem ;
	}
	if(sv[i].truong==3){
		diem3=sv[i].diem;
	}	
	}
	printf("Danh sach diem cac truong la :\n");
	printf("\nDiem truong 1 la :%.2f",diem1);
	printf("Diem truong 2 la :%.2f",diem2);
	printf("\nDiem truong 3 la :%.2f",diem3);
	if(diem1>diem2 && diem1>diem3){
		printf("\n Diem truong 1 co diem so cao nhat ");
	}
	if(diem2>diem1 && diem2>diem3){
		printf("\nDiem truong 2 co diem so cao nhat");
	}
	if (diem3>diem1 && diem3>diem1){
	printf("\nDiem truong 3 co diem so cao nhat ");
}
}
//Nhập vào tên sinh viên,in ra màn hình thông tin của sinh viên đó.
void inSVnhap(struct sinhvien sv[],int n,char ten[]){
	for (int i=1;i<=n;i++){
		if (strcmp(sv[i].ten,ten)==0){// ham kiem tra hai sau giong nhau  dung ham strcmp trong thu vien string.h
    	printf("\nSinh vien thu :%d",i);
		printf("\nTen sinh vien la :%s",sv[i].ten);
		printf("\nMa sinh vien la :%d",sv[i].maSV);
		printf("\nDiem la:%.2f",sv[i].diem);
		printf("\nTen truong la :%d",sv[i].truong);
		}
	}
}
void diemsvmax(struct sinhvien sv[],int n){
	float max=0;
	int vitrimax;
	for (int i=1;i<=n;i++){
		if(max<sv[i].diem){
			max=sv[i].diem;
			vitrimax=i;
		}
	}
	printf("\nSinh vien co diem so max la :%s",sv[vitrimax].ten);
	                  
}
int main (){
	int n;
	printf("Nhap n:");
	scanf("%d",&n);
	char ten[100] ;
	struct sinhvien sv[100];
	nhap(sv,n);
	printf("\nThong tin cac sinh vien la :");
	in(sv,n);
   diemtungtruong(sv,n);
   printf("\nNhap ten sinh vien :");
	fflush (stdin);
	fgets(ten,sizeof(ten),stdin);
   inSVnhap(sv,100,ten);
   diemsvmax( sv,n);
	return 0;
	
	}
