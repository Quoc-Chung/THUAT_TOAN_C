#include<stdio.h>
#include<math.h>
#include<stdlib.h>
struct HinhChuNhat{
	int dai;
	int rong;
};
void LayDuLieuTuFile(HinhChuNhat **h,int &n){
	char duong_dan[100]="C:\\Users\\Admin\\Documents\\LAP TRINH\\DEV C++\\THUATTOANC\\WORK FILE\\LUU TRU\\Bai Tap\\Bai1-4.txt";
	FILE *f;
	f=fopen(duong_dan,"r");
	if(f==NULL){
		printf("\nKhong the  doc duoc file .");
		exit(1);
	}
	fscanf(f,"%d",&n);
	*h=(HinhChuNhat*) malloc (n*sizeof(HinhChuNhat));
	for(int i=0;i<n;i++){
		fscanf(f,"%d%d",&(*h)[i].dai,&(*h)[i].rong);
	}
}
void dientichtrungbinh(HinhChuNhat *h,int n){
	int tong=0;
	for(int i=0;i<n;i++){
		tong+=h[i].dai*h[i].rong;
	}
	printf("\nDien tich trung binh la  :%f",(float)tong/n);
}
void max(HinhChuNhat *h,int n){
	int max=0;
	int dai,rong;
	for(int i=0;i<n;i++){
		if(max<h[i].dai*h[i].rong){
			max=h[i].dai*h[i].rong;
			dai=h[i].dai;
			rong=h[i].rong;
		}
	}
	printf("\nHinh chu nhat co dien tich max co canh :%d %d",dai,rong);
}
int  main (){
	int n;
   HinhChuNhat *h;	
   LayDuLieuTuFile(&h,n);
   dientichtrungbinh(h,n);
   max(h,n);
}
