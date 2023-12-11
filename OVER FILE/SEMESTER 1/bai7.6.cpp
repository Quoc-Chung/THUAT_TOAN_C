//Thông tin về mỗi sinh viên là một cấu trúc gồm các trường: Họ tên, điểm Toán, điểm Văn.
//- Nhập một danh sách gồm n sinh viên của một lớp và in ra màn hình thông tin về n sinh viên vừa nhập.
//- Tìm và in ra màn hình danh sách tất cả các sinh viên có điểm Toán cao nhất và danh sách các sinh viên có điểm Văn 
//thấp nhất.
//- Tìm và in ra màn hình danh sách 3 sinh viên có tổng điểm thấp nhất
#include <stdio.h>
#include <math.h>
struct sinhvien {
	char ten[30];
	float toan;
	float van;
};
void nhapSV(struct sinhvien sv[],int n){
	for (int i=1;i<=n;i++){
		printf("Nhap sinh vien thu %d:\n",i);
		printf("\nNhap ten sinh vien :\n");
		fflush (stdin);
		fgets(sv[i].ten,sizeof(sv[i].ten),stdin);
		printf("Nhap diem Toan va diem Van :");
		scanf("%f %f",&sv[i].toan,&sv[i].van);
	}
}
//Tìm và in ra màn hình danh sách 3 sinh viên có tổng điểm thấp nhất
void insinhvien(struct sinhvien sv[],int n){
	struct sinhvien tam;
	for(int i=1;i<=n;i++)
    for(int j=i+1;j<=n;j++)
    if ((sv[i].toan+sv[i].van) > (sv[j].toan+sv[j].van)){
	             // sap xep vi tri 
                              tam=sv[i];
                              sv[i]=sv[j];
                              sv[j]=tam;
    }
    printf("\n Ba SV co diem so thap nhat la :\n");
    for (int i=1;i<4;i++)     
          printf("%s\n",sv[i].ten);	
}
int main (){
	int n;
	printf("Nhap so n :");
	scanf("%d",&n);
	struct sinhvien sv[100];
	nhapSV(sv,n);
	insinhvien(sv,n);
	return 0;
}
	
