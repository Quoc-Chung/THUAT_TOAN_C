#include <stdio.h>
#include <math.h>
struct diem{
	float x;
	float y;
};
/// nhap n diem
void nhapdiem(struct diem d[],int n){// truyền vào một mảng dinh nghia boi struct 
	for (int i=1;i<=n;i++){
		printf("Nhap toa do diem %d:",i);
		scanf("%f%f",&d[i].x,&d[i].y);
	}
}
void indiem(struct diem d[],int n){
	for (int i=1;i<=n;i++){
		printf("\nToa do diem thu %d la :%.2f--%.2f :\n",i,d[i].x,d[i].y);
	}
}

void tinhdodai(struct  diem d[],int n){
	float dodai=0;
	for (int i=1;i<n;i++){
		dodai+=sqrt(pow(d[i+1].x-d[i].x,2)+pow(d[i+1].y-d[i].y,2));
	}
	printf("Do dai la :%f",dodai);	
}
void toadothoaman(struct diem d[],int n,int r){
	for (int i=1;i<=n;i++){
		if(sqrt (pow(d[i].x,2)+pow(d[i].y,2))<=r)
			printf("%.2f %.2f\n",d[i].x,d[i].y);
	}
}
float dientichthoaman(struct diem d[],int n){
	 float hoanhmax=0;
	 float tungmax=0;
	 float s=0;
	 for (int i=1;i<=n;i++){
	 	if(hoanhmax<=d[i].x){
	 		hoanhmax=d[i].x;
		 }
		if(tungmax<=d[i].y){
			tungmax=d[i].y;
		}
	 }
	 s=sqrt (hoanhmax*hoanhmax+tungmax*tungmax)*3.14;
	 return s;	
	 }
int main (){
	int n;
	printf("Nhap so diem la :");
	scanf("%d",&n);
	float r;
	printf("\nNhap ban kinh kiem tra:");
	scanf("%f",&r);
	struct diem d[100];
	nhapdiem(d,n);
	printf("\nToa do cac diem la :");
	indiem(d,n);
	tinhdodai(d,n);
	printf("\nCac diem trong duong tron la :\n");
	toadothoaman(d,n,r);
	printf("\nDien tich hinh tron thoa man la :%f",dientichthoaman(d,n));
	return 0;
}