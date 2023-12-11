#include <stdio.h>
#include <math.h>
  struct SV{
	char ht [30];
	unsigned int masv;
	char gioi[5];
	char lop[50];
	float diemtb;
} 
SV;

int main (){
	  
	// nhap thong tin cho 1 bien cau truc roi in lai
	printf("Nhap ho ten sinh vien :\n");
	gets(SV.ht);
	printf("Ma sinh vien la :");
	scanf("%d",&SV.masv);
	printf("\nGioi tinh :");
	gets(SV.gioi);
	printf("\nLop :");
	gets(SV.lop);
	scanf("\n Diem trung binh :%f",&SV.diemtb);
	return 0;
	
}