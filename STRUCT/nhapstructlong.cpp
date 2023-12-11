#include <stdio.h>
#include <math.h>
struct date {
	int ngay;
	int thang ;
	int nam ;
};
struct sinhvien{
	char ht[30];
	date ngaysinh;
	unsigned int maSV;
	char khoa[6];
	char lop[10];
	
};
// ham nhap ta nen truyen tham chieu de gia tri bien co the thaay doi khi ham ket thuc 
 void inputSV(struct sinhvien &sv){
	printf("Nhap ten sinh vien :");
	scanf("%s",&sv.ht);
	printf("\nNhap ngay sinh:");
	scanf("%d%d%d", &sv.ngaysinh.ngay,&sv.ngaysinh.thang, &sv.ngaysinh.nam);
	 printf("\nMa sinh vien :");
	 scanf("%d",&sv.maSV);
	 printf("\nKhoa:");
	 scanf("%s",&sv.khoa);
	 printf("\nNhap lop:");
	 scanf("%s",&sv.lop);
}
// ham in ta khong truyen bien tham chieu 
void printfSV(struct sinhvien sv){
     printf("Nhap ten sinh vien :");
     printf("%s",sv.ht);
	 printf("\nNgay sinh:");
	 // de co the dung hai struct long nhau thi ta chi can cho dac ta la dac ta cua cac bien vong for "duoc" long ,sau do
	 // ta thuc hien truyen bien struct tu  sv.tenbienmoikhaibaotukieustructduoclong.bientamuonkhaibao(vidu sv.ngaysinh.ngay)
	 printf("%d /%d /%d", sv.ngaysinh.ngay, sv.ngaysinh.thang, sv.ngaysinh.nam);
	 printf("\nMa sinh vien :");
	 printf("%d",sv.maSV);
	 printf("\nKhoa:");
     printf("%s",sv.khoa);
	 printf("\nLop:");
	 printf("%s",sv.lop);
}
int main (){
	struct sinhvien sv;
	inputSV(sv);
	printfSV(sv);
	return 0;
}