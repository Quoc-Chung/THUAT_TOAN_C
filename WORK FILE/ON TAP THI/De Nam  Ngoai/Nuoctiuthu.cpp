#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
struct NuocTieuThu{
	char TenChuHo[50];
	char DiaChi[50];
	int  MaSo;
	int SoNuoc;
};
void  DocFile(NuocTieuThu **d,int &n, char *tentep){
	FILE *f=fopen(tentep,"r");
	if(f==NULL){
		printf("\nKhong the  mo duoc file");
		exit(0);
	}
	fscanf(f,"%d",&n);
	(*d)=(NuocTieuThu *) malloc  (n*sizeof(NuocTieuThu));
	for (int i=0;i<n;i++){
		fscanf(f," %[^\n]",(*d)[i].TenChuHo);
		fscanf(f," %[^\n]",(*d)[i].DiaChi);
		fscanf(f,"%d",&(*d)[i].MaSo);
		fscanf(f,"%d",&(*d)[i].SoNuoc);
	}
   printf("\nThong  tin  Ho Gia Dinh:\n");
   for(int i=0;i<n;i++){
   	 printf("\nGia Dinh Thu %d:\n",i+1);
   	 printf("\nTen Chu Ho :%s -- Dia Chi :%s -Ma So :%d --So Nuoc: %d",(*d)[i].TenChuHo,(*d)[i].DiaChi,(*d)[i].MaSo,(*d)[i].SoNuoc);
   }
}
int TienNuoc(int SoNuoc) {
	if (SoNuoc <= 10) {
		return 5000 * SoNuoc;
	}
	else if (SoNuoc > 10 && SoNuoc <= 20) {
		return 10 * 5000 + (SoNuoc - 10) * 6200;
	}
	else if (SoNuoc > 20 && SoNuoc <= 30) {
		return 10 * 5000 + 10 * 6200 + (SoNuoc - 20) * 9000;
	}
	else {
		return 10 * 5000 + 10 * 6200 + 10 * 9000 + (SoNuoc - 30) * 16000;
	}
}
void TienNuocTrungBinh(NuocTieuThu *d, int n) {
	int tong = 0;
	float tien = 0;
	for (int i = 0;i < n; i++) {
		tong +=TienNuoc(d[i].SoNuoc);
	}
	int x=n;
	tien=(float)tong / x;
	printf("\nTien Nuoc Trung Binh La: %.2f", tien);
}
void TimThongTin(NuocTieuThu *d, int n) {
	int maso;
	bool  check =false;
	printf("\nNhap ma so tim kiem:");
	scanf("%d",&maso);
	for (int i = 0;i < n;i++) {
		if (maso == d[i].MaSo) {
			printf("\nTien Nuoc Phai Dong: %d", TienNuoc(d[i].SoNuoc));
			check = true;
			break;
		}
	}
	if (check == false) {
		printf("\nKhong tim thay");
	}
}
int  main (){
	int n;
	NuocTieuThu *d;
	char tentep[50]="NuocTieuThu.txt";
	DocFile(&d,n,tentep);
	TienNuocTrungBinh(d,n);
	TimThongTin(d,n);
	return 0;
}