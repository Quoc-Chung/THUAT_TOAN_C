#include <stdio.h>
#include <math.h>
// typedef:   dinh nghia kieu thanh ten moi 
typedef struct ngay {
	int ngay;
	int thang;
	int nam;
};
int main(){
	// toan tu dau cham(.) de truy cap vao thanh phan cua cau truc 
	ngay a;
	scanf("%d",&a.ngay);
	printf("Ngay vua nhap la :%d",a.ngay);
     a.thang=a.ngay;
	scanf("%d",&a.thang);
	printf("\nThang vua nhap la :%d",a.thang);
	
	scanf("%d",&a.nam);
	printf("\nNam vua nhap la :%d",a.nam);
	printf("\n Ngay %d thang %d nam %d ",a.ngay,a.thang,a.nam);
	
	
}
// gan gia tri cac bien co cung kieu cau truc 
// cau truc ve trai nhan gia tri cau truc ve phai
//