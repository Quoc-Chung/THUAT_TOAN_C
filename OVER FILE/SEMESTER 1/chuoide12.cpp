#include <stdio.h>
#include <math.h>
struct diem{
	int h;
	int t;
	
};
void nhap(diem d[],int n){
	for (int i=1;i<=n;i++){
		printf ("\nNhap diem %d:",i);
		scanf("%d%d",&d[i].h,&d[i].t);
	}
}
void indiem (diem d[],int n){
	printf("\tDANH SACH DIEM:\n");
	for (int i=1;i<=n;i++){
		printf("(%d,%d)\t",d[i].h,d[i].t);
	}
}
// tinh tong khoang cach cac diem den  truc ox
void tong(diem d[],int n){
	int tong=0;
	for (int i=1;i<=n;i++){
		tong+=abs(d[i].t);
	}
	printf("\nTong khoang cach cac diem den truc ox: %d",tong);
}
// xac dinh 3 diem gan tam 0 nhat >> sap xep khoang cach theo chieu tang dan 
float khoangcach (int x,int y){
	float kc=1.0*sqrt(x*x+y*y);
	return kc;
}
void badiem(diem d[],int n){
	struct diem tam;
	for (int i=1;i<=n;i++){
		for (int j=1;j<n;j++){
			if(khoangcach(d[i].h,d[i].t)<khoangcach(d[j].h,d[j].t)){
				tam=d[i];
				d[i]=d[j];
				d[j]= tam;
			}
		}
	}
	printf("\nBa diem gan toa do nhat la :\n");
	for (int i=1;i<=3;i++){
		printf("(%d,%d)\t ",d[i].h,d[i].t);
	}
}
// tim cac diem nam o goc phan tu thu 3 va nam tren duong thang  y=x;
// diem goc phan tu thu 3:hoanh tung deu nho hon 0
void timdiem(diem d[],int n){
	int hoanh,tung;
	int dem=0;
	printf("\nSo diem thoa man la :\n");
	for (int i=1;i<=n;i++){
		hoanh =0;
		tung=0;
		if(d[i].h<0 && d[i].t<0 && d[i].h==d[i].t){
			hoanh=d[i].h;
			tung=d[i].t;
			printf("\n(%d,%d) ",hoanh,tung);
			dem++;
		}
	}
	printf("\nSo diem thoa man la :%d ",dem);
}
//Tinh dien tich duong tron C co tam (x,y) sao cho vong tron chua tat ca cac diem con lai 
void dientich_chuadiem(diem d[],int n){
	   float r=0;
	for (int i=1;i<=n;i++){
		if(r<sqrt(d[i].h*d[i].h+d[i].t*d[i].t)){
			r=sqrt(d[i].h*d[i].h+d[i].t*d[i].t);
		}
	}
	printf("Dien tich hinh tron chua cac diem :%.2f",3.14*r*r);
}
int main (){
	int n;
	struct diem d[100];
	do {
		printf("\nNhap n:");
		scanf("%d",&n);
		if(n<1){
			printf("\nVui long nhap lai so n.");
		}
	}while (n<1);
	nhap(d,n);
	indiem(d,n);
//	tong(d,n);
//	badiem(d,n);
   //timdiem(d,n);
   dientich_chuadiem(d,n);
   return 0;
	
}