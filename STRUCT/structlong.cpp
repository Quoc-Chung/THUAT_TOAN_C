#include <stdio.h>
#include <math.h>
struct tongket {
	float toan;
	float hoa;
	float li;
};
struct ngaysinh {
	int ngay ;
	int thang ;
	int nam ;
};
struct sinhvien {
	int maSV;
	char ten[30];
    struct ngaysinh sinhnhat;
    struct tongket diem;  
};
void nhap(struct sinhvien sv[],int n){
	for (int i=1;i<=n;i++){
	  
	   printf("\nNhap ten sinh vien :");
	   fflush (stdin);
	   fgets(sv[i].ten,sizeof(sv[i].ten),stdin); 
	   printf("Nhap ma sinh vien :");
	   scanf("%d",&sv[i].maSV);
	   printf("Nhap vao ngay sinh :");
	   scanf("%d%d%d",&sv[i].sinhnhat.ngay,&sv[i].sinhnhat.thang,&sv[i].sinhnhat.nam);	
		//sv[i].(bien sinh nhat vua dinh nghia ).(ten bien long )
	   printf("Nhap diem :\n");
	   printf("\nDiem toan :");
	   scanf("%f",&sv[i].diem.toan);
	   printf("\nDiem hoa:");
	   scanf("%f",&sv[i].diem.hoa);
	   printf("\nDiem li :");
	   scanf("%f",&sv[i].diem.li);
	}
}
void in (struct sinhvien sv[],int n){
	for (int i=1;i<=n;i++){
	   printf("\nMa sinh vien la :%d",sv[i].maSV);
	   printf("\nTen sinh vien :%s",sv[i].ten);
	   printf("\nNgay sinh :%d %d %d",sv[i].sinhnhat.ngay,sv[i].sinhnhat.thang,sv[i].sinhnhat.nam);
	   printf("\nDiem toan - hoa - li :%.2f %.2f %.2f",sv[i].diem.toan,sv[i].diem.hoa,sv[i].diem.li);
}
}
int main (){
	int n;
	printf("Nhap n:");
	scanf("%d",&n);
	struct sinhvien sv[100];
	nhap(sv,n);
	in(sv,n);
}