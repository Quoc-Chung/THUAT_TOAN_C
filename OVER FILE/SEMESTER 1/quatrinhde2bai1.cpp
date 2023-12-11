//Nhập, xuất vào một dãy có n điểm, thực hiện các yêu cầu sau:
///- Đếm số điểm thuộc góc phần tư thứ 3.-->hoanh duong ,tung am 
//- Tìm các điểm xa gốc tọa độ nhất.--> la dieem co do dai dai nhat vs goc toa do sqrt (x2+y2) max
//- Hãy cho biết số đoạn thẳng cắt trục hoành -> dem so đoạn thẳng cat truc hoanh 
#include <stdio.h>
#include <math.h>
struct diem{
	int h;// hoanh 
	int t;// tung
};
void nhapdiem(struct diem d[],int n){
	for (int i=1;i<=n;i++){
	 printf("Nhap diem thu %d:",i);
	 scanf("%d %d",&d[i].h,&d[i].t);	
	}
}
void indiem (struct diem d[],int n){
	for (int i=1;i<=n;i++){
		printf("%d %d\n",d[i].h,d[i].t);
	}
}
//Đếm số điểm thuộc góc phần tư thứ 3.-->hoanh duong ,tung am 
void demdiem(struct diem d[],int n){
	int dem =0;
	for (int i=1;i<=n;i++){
		if(d[i].h<0 && d[i].t>0)
		dem ++;
	}
	if(dem ==0){
		printf("Khong co diem nào trong goc phan tu thu 3");
	}
	else {
	printf("So diem o goc phan tu thu 3 la :%d",dem );
}
}
//Tìm các điểm xa gốc tọa độ nhất--> la diem co do dai dai nhat vs goc toa do sqrt (x2+y2) max
void diemxaOnhat(struct diem d[],int n){
	float max=0;
	int toadoh;
	int toadot;
	for (int i=1;i<=n;i++){
		if (max<=sqrt (d[i].h*d[i].h+d[i].t*d[i].t)){
		 max=sqrt (d[i].h*d[i].h+d[i].t*d[i].t);
		 toadoh=d[i].h;
		 toadot=d[i].t;
		
		}
	}
 printf("\nToa do xa tam nhat la :%d %d",toadoh,toadot);
}
// Hãy cho biết số đoạn thẳng cắt trục hoành -> dem so đoạn thẳng cat truc hoanh
// bi loi 
void sodoanthang(struct diem d[],int n){
	int dem=0;
	for (int i=1;i<=n;i++){
		for (int j=i+1;j<=n;j++){
		if(d[i].t*d[j].t<0){
					dem++ ;
				}
			}
	}
	printf("\nSo doan thang cat truc hoanh :%d",dem);
}
int main (){
	int n;
	printf("Nhap n :");
	scanf("%d",&n);
	struct diem d[100];
	nhapdiem (d,n);
	printf("\nCac diem vua nhap :\n");
	indiem (d,n);
	demdiem(d,n);
	diemxaOnhat(d,n);
	sodoanthang(d,n);
	return 0;//Trong lập trình ngầm định dùng return 0; để báo cáo chương trình đã chạy hết và không gặp một lỗi nào.
	// Nếu trả về khác 0, chương trình đã chạy hết và có lỗi xảy ra. 
}