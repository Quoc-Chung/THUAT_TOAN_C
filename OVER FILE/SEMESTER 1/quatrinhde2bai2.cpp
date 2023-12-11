// Định nghĩa một cấu trúc Sách gồm các thành phần: Mã sách, tên sách, tên tác giả, 
//  giá tiền. Nhập, xuất n cuốn sách.
// Nhâp vào tên một tác giả, in ra màn hình những cuốn sách của tác giả đó.
// Cho biết cuốn sách nào đắt nhất.
// Đếm những cuốn sách có giá lớn hơn 100
#include <stdio.h>
#include <math.h>
#include <string.h>
struct sach {
	int ma;
	char ten[30];
	char tentacgia[30];
	unsigned int tien;
};
void nhapsach (struct sach s[],int n){
	for (int i=1;i<=n;i++){
	  printf("Sach thu %d",i);
	  printf("\nNhap ma sach :");
	  scanf("%d",&s[i].ma);
	  printf("\nNhap ten sach :");
	   fflush(stdin);
	  fgets(s[i].ten,sizeof(s[i].ten),stdin);
	  printf("\nNhap ten tac gia :");
	  fflush(stdin);
	  fgets(s[i].tentacgia,sizeof(s[i].tentacgia),stdin);
	  printf("\nNhap gia tien:");
	  scanf("%d",&s[i].tien);	
	}
}
void insach(struct sach s[],int n){
	for (int i=1;i<=n;i++){
		printf("\nSach thu %d",i);
		printf("\nMa sach la :%d",s[i].ma);
		printf("\nTen sach la :%s",s[i].ten);
		printf("\nTen tac gia :%s",s[i].tentacgia);
		printf("\nGia tien :%d",s[i].tien);	
	}
}
void nhaptentacgia(struct sach s[],int n,char ten[]){
	int flag=0;
	for (int i=1;i<=n;i++){
		if(strcmp(s[i].tentacgia,ten)==0){
			flag++;
			printf("\n:%s",s[i].ten);
		}
		
	}
	if(flag==0){
		printf("\nKhong co sach tac gia viet");
	}
}
void sachdatcatco(struct sach s[],int n){
	int max=0;
	int vitri=0;
	for (int i=1;i<=n;i++){
		if (max<s[i].tien){
			max=s[i].tien;
			vitri=i;
		}
	}
	printf("\nSach max nhat la :%s",s[vitri].ten);
}
int  demsach(struct sach s[],int n){
	int dem=0;
	for (int i=1;i<=n;i++){
		if(s[i].tien > 100){
			dem ++;
		}
	}
	return dem ;
}
int main (){
	int n;
	printf("Nhap so luong:");
	scanf("%d",&n);
	struct sach s[100];
	nhapsach(s,n);
	insach (s,n);
	char tacgia[30];
	printf("Nhap ten tac gia:");
	fflush(stdin);
	fgets(tacgia,sizeof(tacgia),stdin);
	printf("Sach cua tac gia %s:\n",tacgia);
	nhaptentacgia(s,n,tacgia);
	sachdatcatco(s,n);
	printf("\nSo sach co gia hon 100 la :%d",demsach(s,n));
	return 0;
}