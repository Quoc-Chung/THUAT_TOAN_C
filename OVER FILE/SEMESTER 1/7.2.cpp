// Thông tin của mỗi sinh viên là một cấu trúc gồm các trường: Họ tên, Điểm toán, Điểm lý, Điểm hoá
// Nhập một danh sách gồm n sinh viên và in ra màn hình thông tin về n sinh viên vừa nhập.
// Tìm và in ra màn hình danh sách các sinh viên bị thi lại (nếu điểm thi nhỏ hơn 5) một trong ba môn Toán, Lý, Hoá.
//  Nhập vào tên của một sinh viên bất kỳ, tìm xem trong lớp có sinh viên đó không? Nếu có thì in thông tin của sinh 
//viên đó ra màn hình.
#include <stdio.h>
#include <math.h>
#include <string.h>
struct SV {
	char hoten[30];
	float toan;
	float ly;
	float hoa;
};
void nhapSV(SV *pt){// truyen con tro thi dung  &contro  de su dung trong ham, dung mui ten de tro den ham va luc goi ra thi ta goi dia chi &
	printf("Ten sinh vien la :");
	scanf("%s",&pt->hoten);
	printf("\n Diem toan :");
	scanf("%f",&pt->toan);
	printf("\nDiem ly :");
	scanf("%f",&pt->ly);
	printf("\nDiem hoa :");
	scanf("%f",&pt->hoa);
}
void inSV(SV pt){//in ra thi khong can bien con tro 
	printf("Ten sinh vien la :%s",pt.hoten);
	printf("\n Dem toan :%.2f",pt.toan);
	printf("\nDiem ly :%.2f",pt.ly);
	printf("\nDiem hoa :%.2f",pt.hoa);
}
void inbonngu(SV pt){
	printf("Ten sinh vien la :%s\n",pt.hoten);
}
int  Kiemtra (SV pt){
	if(pt.hoa<5 || pt.ly<5 || pt.toan<5){
		return 0;
	}
	else {
	return 1;
}
}
void kiemtraxuathien(SV *pt,char x[10]){
	if(strcmp(pt->hoten,x)==0){// day la hâm so sanh hai chuoi neu 
		printf("Ho ten sinh vien co mat la:%s",pt->hoten);
	}
	
	else {
		printf("Sinh vien khong co  ! ");
	}
	
}
int main (){
	  struct SV sv,sv1;// dinh nghia khai bao mot bien chung cua cau truc struct 
	int n;
	printf("Nhap so n:");
	scanf("%d",&n);

	
	for (int i=1;i<=n;i++){
		printf("Thong tin sinh vien thu :%d\n",i);
		nhapSV(&sv);// truyen dia chi bien vua dinh nghia vao voi vai tro la  mot con tro 
	}
	for (int i=1;i<=n;i++){
		printf("\nTHONG TIN SINH VIEN THU :%d\n",i);
		inSV(sv);
	}printf("\nCac sinh vien bi thi lai  :\n");
	for (int i=1;i<=n;i++){
		if(Kiemtra(sv)==0)
			inbonngu(sv);
			break;
		
	}
	// dang sai o phan cuoi nay
	printf("\nNhap ten sinh vien kiem tra:");
	char x[30];
	scanf("%s",&x);
    kiemtraxuathien(&sv,x);
}
#include<stdio.h>
#include <string.h>
 // day la ham kiem tra hai chuoi giong nhau 
//int main() {    
 // char str1[20], str2[20];    
 // printf("Nhap chuoi 1: ");
 // gets(str1); 
 // printf("Nhap chuoi 2: ");
 // gets(str2);
  //if (strcmp(str1, str2) == 0) {
   //printf("2 chuoi bang nhau.");
  //} else if (strcmp(str1, str2) > 0) {
  // printf("Chuoi 1 lon hon chuoi 2");
  //} else {
  // printf("Chuoi 1 nho hon chuoi 2");
  //}
  //return 0;
//}