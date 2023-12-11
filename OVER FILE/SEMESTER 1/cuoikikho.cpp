
//tinh dien tich duong tron  (c) co tam (xi,yi) sao cho vong tron (C) chua tat ca cac diem con lai 
// tinh dien tich duong tron co toa do (x,y) co ban kinh R nho nhat sao cho no chua tat ca cac diem con lai 
#include <stdio.h>
#include <math.h>
struct toado{
	int h;
	int t;
};
void nhapdiem(toado d[],int n){
	printf("\tNHAP DIEM :\n");
	for (int i=1;i<=n;i++){
		printf("\nDiem %d:",i);
		scanf("%d %d",&d[i].h,&d[i].t);
	}
}
void indiem(toado d[],int n){
	printf("\n\tDIEM VUA NHAP:\n");
	for (int i=1;i<=n;i++){
		printf("\nDiem thu %d:",i);
		printf("(%d , %d)",d[i].h,d[i].t);
	}
	
}
// cách tìm tâm của các điểm chính là trung bình cộng của hoành và trung bình cộng của tung 
//>> tâm duong tron la (x,y)
// tiếp theo tìm bán kính bằng cách tìm khoảng cách lớn nhất giữa các điểm với tâm x,y vừa tìm được 
//>> khoảng cách nào lớn nhất  thì đây chính là bán kinh 
void dientich (toado d[],int n){
	int tonghoanh=0,tongtung=0;
	float r=0;
	for (int i=1;i<=n;i++){
		tonghoanh+=d[i].h;
		tongtung +=d[i].t;
	}
	float x_center=(float)tonghoanh/n;
	float y_center=(float)tongtung/n;
	printf("\n%.2f %.2f",x_center,y_center);
	for (int i=1;i<=n;i++){
		float tam=1.0*sqrt(pow(d[i].h-x_center,2)+pow(d[i].t-y_center,2));
		if(r<tam){
			r=tam;
		}
	}
	
	float dientich=3.14*r*r;
	printf("\nDien tich nho nhat chua tat ca cac diem la :%.2f",dientich);
}
//xac dinh do dai duong gap khuc di qua hai diem (1,2,...n) va (2 3 ...n)
void dodaigapkhuc(toado d[],int n){
	float tong =0;
	for (int i=1;i<n;i++){
		//d[i].h=(float)d[i].h;
	///	d[i].t=(float)d[i].t;
		tong+= sqrt(pow(d[i+1].h-d[i].h,2)+pow(d[i+1].t-d[i].t,2));
	}
	printf("\nDo dai duong gap khuc :%.2f",tong);
}

// tinh khoang cach cua tung diem den tam 0;
void khoangcach (toado d[],int n){
	float kc;
	int vitri;
	for (int i=1;i<=n;i++){
		kc=0,vitri=0;
	    kc=sqrt(d[i].h*d[i].h+d[i].t*d[i].t);
	    vitri=i;
	    printf("\nKhoang cach diem %d den tam 0 la :%.2f",vitri,kc);
	}
	// ep kieu mo :))
}
int main (){
	int n;
	printf("\nNhap n:");
	scanf("%d",&n);
	struct toado d[100];
	nhapdiem(d,n);
	indiem(d,n);
	dodaigapkhuc(d,n);
//	khoangcach(d,n);
   // dientich(d,n);
	return 0;	
}