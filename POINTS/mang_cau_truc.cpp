#include <stdio.h>
#include <math.h>
#include <stdlib.h>
struct hoten{
  char ten[30];	
  int tuoi;
};
// ví dụ trên cho thấy cần phải truyền tham chiếu thì mới lưu được giá trị nhập  
//void nhap_ten(struct hoten &ht){
//	printf("\nNhap ho ten :");
//	fflush(stdin);
//	fgets(ht.ten,sizeof(ht.ten),stdin);
//	printf("\nNhap tuoi:");
//	scanf("%d",&ht.tuoi);
//	
//	
//	// in giá trị trong hàm  
//	printf("\nHo ten la :%s",ht.ten);
//	printf("\nTuoi :%d",ht.tuoi);
//	
//	
//}
//// muốn thay đổi giá trị và lưu lại nhưng gì đã hay đổi thì phải 
//void nhap_ten_khong_truyen_tham_chieu(struct hoten ht){
//	printf("\nNhap ho ten :");
//	fflush(stdin);
//	fgets(ht.ten,sizeof(ht.ten),stdin);
//	printf("\nNhap tuoi:");
//	scanf("%d",&ht.tuoi);
//	
//	
//	// in giá trị trong hàm  
//	printf("\nHo ten la :%s",ht.ten);
//	printf("\nTuoi :%d",ht.tuoi);
//}
//void nhap_truyen_con_tro(struct hoten *ht){
//	printf("\nNhap ho ten :");
//	fflush(stdin);
//	fgets(ht->ten,sizeof(ht->ten),stdin);
//	printf("\nNhap tuoi:");
//	scanf("%d",&ht->tuoi);
//	
//	
//	// in giá trị trong hàm  
//	printf("\nHo ten la :%s",ht->ten);
//	printf("\nTuoi :%d",ht->tuoi);
//}
//void nhap_nhieu(struct hoten ht[],int n){
//	for (int i=1;i<=n;i++){
//	printf("\nNhap ho ten :");
//	fflush(stdin);
//	fgets(ht[i].ten,sizeof(ht[i].ten),stdin);
//	printf("\nNhap tuoi:");
//	scanf("%d",&ht[i].tuoi);
//	}
//}
//// không thể cap nhat uoc ho va tên khi khong truyen tham chieu 
//// ta co the thay doi gia tri bang cach nay nua 
//void in(struct hoten ht){
//	printf("\nHo ten la :%s",ht.ten);
//	printf("\nTuoi :%d",ht.tuoi);
//}
//void in_nhieu(struct hoten ht[],int n){
//	for (int i=1;i<=n;i++){
//		printf("\nHo ten la :%s",ht[i].ten);
//    	printf("\nTuoi :%d",ht[i].tuoi);
//	}
//}
//// con tro bay gio phai mang kieu struct thì mới có thể lưu được địa chỉ của biến cấu trúc 
//// riêng về mảng con tro phai khoi tao tu 0 tro đi 
//void nhap_con_tro(struct hoten *ht[],int n){
//	for (int i=0;i<n;i++){
//	printf("\nNhap ho ten :");
//	fflush(stdin);
//	fgets(ht[i]->ten,sizeof(ht[i]->ten),stdin);
//	printf("\nNhap tuoi:");
//	scanf("%d",&ht[i]->tuoi);
//        }
//}
//void in_bang_con_tro(struct hoten *ht[],int n){
//	for (int i=0;i<n;i++){
//		printf("\nHo ten la :%s",ht[i]->ten);
//	    printf("\nTuoi :%d",ht[i]->tuoi);
//	}
//}
void nhap_1nguoi_con_tro(struct hoten *ht){
	printf("\nNhap ho ten :");
	fflush(stdin);
	fgets(ht->ten,sizeof(ht->ten),stdin);
	printf("\nNhap tuoi:");
	scanf("%d",&ht->tuoi);
}
void nhap_nhieu_nguoi(struct hoten ht[],int n){
	for (int i=0;i<n;i++){
		nhap_1nguoi_con_tro(&ht[i]);
	}
}
void in_1_nguoi(struct hoten *ht){
	printf("\nHo ten la :%s",ht->ten);
	printf("\nTuoi :%d",ht->tuoi);
}
void in_nhieu_nguoi(struct hoten ht[],int n){
	for (int i=0;i<n;i++){
		in_1_nguoi(&ht[i]);
	}
}
int main (){
	int n=2;
	struct hoten ht[100];
	nhap_nhieu_nguoi(ht,n);
	in_nhieu_nguoi(ht,n);
//	struct hoten *ht[100];
//	// vì ta truyền mảng con trỏ vào hàm nên ta phải cấp phát cho từng con tro trong mang 
//	for (int i=0;i<n;i++){
//			ht[i] = (hoten *)malloc(sizeof(hoten));
//	}
//    nhap_con_tro(ht,n);
//    in_bang_con_tro(ht,n);
//    free(ht);
//	return 0;











}
