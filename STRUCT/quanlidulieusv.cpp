#include <stdio.h>
#include <math.h>
struct date {
	int ngay,thang,nam;
};
struct sinhvien{
	char maSV[5];
	char hoten[30];
	date ngaysinh;
	date ngaynhaphoc;
	char lop[7];
	float dtb;
};
void nhap1SV(sinhvien &sv){// truyen tham chieu thì mới nhap luon trong hàm dược 
// ta hay làm theo cach trruyen mang thì không cần truyền tham chiếu vì thực chát mảng là một con trỏ
	printf("\nNhap maSV:");
	fflush(stdin);
	fgets(sv.maSV,sizeof(sv.maSV),stdin);
	printf("\nNhap ho va ten :");
	fflush(stdin);
	fgets(sv.hoten,sizeof(sv.hoten),stdin);
	printf("\nNhap ngay sinh :");
	scanf("%d%d%d",&sv.ngaysinh.ngay,&sv.ngaysinh.thang,&sv.ngaysinh.nam);
	printf("\nNhap ngay nhap hoc:");
	scanf("%d%d%d",&sv.ngaynhaphoc.ngay,&sv.ngaynhaphoc.thang,&sv.ngaynhaphoc.nam);
	printf("\nNhap lop:");
	fflush(stdin);
	fgets(sv.lop,sizeof(sv.lop),stdin);
	printf("\nNhap diem trung binh :");
	scanf("%f",sv.dtb);
	
}


int main (){
	int n;
	struct sinhvien sv;
}