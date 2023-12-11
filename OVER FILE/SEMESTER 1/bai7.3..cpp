//Thông tin của mỗi sinh viên là một cấu trúc gồm các trường: Họ tên, Điểm toán, Điểm lý, Điểm hoá
//Nhập một danh sách gồm n sinh viên và in ra màn hình thông tin về n sinh viên vừa nhập.
// Tìm và in ra màn hình danh sách các sinh viên bị thi lại (nếu điểm thi nhỏ hơn 5) một trong ba môn Toán, Lý, Hoá.
#include <stdio.h>
#include <math.h>
struct sinhvien{
	char ten[30];
    float toan;
    float li;
    float hoa;
};
void nhapSV(struct sinhvien sv[],int n){
	for (int i=1;i<=n;i++){
		printf("\nNhap ten sinh vien :");
		fflush(stdin);
		fgets(sv[i].ten,sizeof(sv[i].ten),stdin);
		printf("Nhap diem toan li hoa :");
		scanf("%f %f %f",&sv[i].toan,&sv[i].li,&sv[i].hoa);
	}
}
void kiemtra (struct sinhvien sv[],int n){
	int vitri;
	printf("Sinh vien thi lai la :\n");
	for (int i=1;i<=n;i++){
		vitri=0;
		if(sv[i].toan<5 || sv[i].li<5 || sv[i].hoa<5){
			vitri=i;
			printf("%s",sv[vitri].ten);
		}
	}
}
int main (){
	int n;
	scanf("%d",&n);
	struct sinhvien sv[100];
	nhapSV(sv,n);
	kiemtra(sv,n);
	return 0;
}