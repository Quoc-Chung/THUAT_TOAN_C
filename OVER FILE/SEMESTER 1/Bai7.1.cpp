// Định nghĩa cấu trúc SV gồm các thông tin: họ tên, mã sinh viên, giới tính, lớp, điểm trung bình. Nhập thông 
// tin cho 1 biến cấu trúc từ bàn phím rồi in lại thông tin đó ra màn hình.
#include <stdio.h>
#include <math.h>
struct thongtin{
	char hoten[30];
	unsigned int maSV;
	char gioitinh[5];
	char lop[7];
	float diemTB;
	
};
int main (){
	struct thongtin SV;
	printf("Nhap ten sinh vien :\n");
	gets(SV.hoten);
	printf("Nhap ma sinh vien:");
	scanf("%d",&SV.maSV);
    printf("\nGioi tinh :");
    scanf("%s",&SV.gioitinh);
	printf("\nLop:");
    scanf("%s",&SV.lop);
    printf("Diem trung binh :");
    scanf("%f",&SV.diemTB);
    printf("\nCAC THONG TIN SINH VIEN LA :\n");
    printf("Ten sinh vien :%s\n Ma Sinh vien :%d\n Lop:%s\n Gioitinh :%s\n Diem trung binh :%.2f",SV.hoten,SV.maSV,SV.lop,SV.gioitinh,SV.diemTB);
}
