//Thông tin của mỗi cầu thủ là một cấu trúc gồm các trường: HT (Họ tên), SBT (Số bàn thắng), SP (Số phút 
//thi đấu), T (Tiền thưởng).
// Nhập danh sách n cầu thủ (chỉ nhập HT, SBT, SP) và in ra màn hình thông tin của n cầu thủ vừa nhập.
// Tính và in ra màn hình tiền thưởng (T) cho mỗi cầu thủ, biết rằng: Nếu thi đấu từ 500 phút trở lên hoặc ghi được từ
// bàn thắng trở lên thì được thưởng 2 triệu đồng. Nếu đạt cả hai điều kiện trên thì được thưởng 5 triệu đồng. Nếu 
//không đạt cả 2 điều kiện trên thì không được thưởng.
// Tìm và in ra màn hình danh sách tất cả những cầu thủ có tiền thưởng cao nhất đội
#include <stdio.h>
#include <math.h>
#include <string.h>
struct cauthu{
	char ht[30];
	int ban;
	int ptd;
    unsigned long long tienthuong;
};
void nhapcauthu (cauthu &ct){
	printf("Ho ten cau thu :");
	scanf("%s",&ct.ht);
	printf("\nNhap so ban thang:");
	scanf("%d",&ct.ban);
	printf("\nNhap so phut thi dau :");
	scanf("%d",&ct.ptd);
	
}
void incauthu(cauthu ct){
	printf("\nHo va ten cau thu :%s",ct.ht);
	printf("\nSo ban thang cua cau thu :%d",ct.ban);
	printf("\nSo phut thi dau :%d",ct.ptd);
}
void Tinhtienthuong(struct cauthu &ct,int n){
		for (int i=1;i<=n;i++){
	   if(ct.ptd>=500 && ct.ban>=2){
			ct.tienthuong=5000000;
			printf("Tien thuong cua cau thu thu %d la:%lld",i,ct.tienthuong);
		
		}
		if(ct.ptd>=500 || ct.ban >=2){
	     	ct.tienthuong=2000000;
			printf("Tien thuong cua cau thu thu %d la:%lld",i,ct.tienthuong);
		}
		else {
				ct.tienthuong=0;
				printf("Tien thuong cua cau thu thu %d la:%lld",i,ct.tienthuong);
		}
}
}
int main (){
	int n;
	printf("Nhap so n:");
	scanf("%d",&n);
	struct cauthu  ct;// dinh nghia mot bien struct de truy cap ,hoac co the hieu day la bien de truyen gia tri con tro
	for (int i=1;i<=n;i++){
		printf("\nNhap thong tin cau thu %d:\n",i);
		nhapcauthu (ct);
	}
	printf("Thong tin cac cau thu la :\n");
	for (int i=1;i<=n;i++){
		incauthu (ct);
		printf("\n");
	}
	Tinhtienthuong(ct, n);
}



