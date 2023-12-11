#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
struct CuaHang{
	char TenHang[30];
	float Gia;
	int SoLuong;
};
void DocFile(CuaHang **c,int &n,char *tentep){
	FILE *f=fopen(tentep,"r");
	if(f==NULL){
		printf("\nKhong the mo duoc file.");
		exit(0);
	}
	fscanf(f,"%d",&n);
	(*c)=(CuaHang *) malloc(n*sizeof(CuaHang));
	for (int i=0;i<n;i++){
		fscanf(f," %[^\n]",(*c)[i].TenHang);
		fscanf(f,"%f",&(*c)[i].Gia);
		fscanf(f,"%d",&(*c)[i].SoLuong);
	}
	printf("\nThong tin mat hang la :\n");
	for(int i=0;i<n;i++){
		printf("\nMat hang :%s -- Gia: %.2f -- So Luong :%d",(*c)[i].TenHang,(*c)[i].Gia,(*c)[i].SoLuong);
	}
}
void TongTienCuaHang(CuaHang *c ,int n){
	float Tong=0;
	for(int i=0;i<n;i++){
		Tong += c[i].SoLuong*c[i].Gia;
	}
	printf("\nTong tien hang cua cua hang la :%.2f",Tong);
}
void SapXep(CuaHang *c,int n,FILE *f=stdout){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(c[i].SoLuong >c[j].SoLuong){
			CuaHang tmp =c[i];
			c[i]=c[j];
			c[j]=tmp;
			}			
		}
	}
  fprintf(f,"\nThong tin  mat hang da sap xep :\n");
  for(int i=0;i<n;i++){
  	fprintf(f,"\nMat hang :%s -- Gia: %.2f -- So Luong :%d",(c)[i].TenHang,(c)[i].Gia,(c)[i].SoLuong);
  }
}
void  MatHangThoaMan(CuaHang *c ,int n,FILE *f=stdout){
	fprintf(f,"\nThong tin mat hang co gia tren 10000 :\n");
	for(int i=0;i<n;i++){
		if(c[i].Gia >10000){
				fprintf(f,"\nMat hang :%s -- Gia: %.2f -- So Luong :%d",(c)[i].TenHang,(c)[i].Gia,(c)[i].SoLuong);
		}
	}
}
int main(){
	int n;
	CuaHang *c;
	char tentep[50]="cuahang.txt";
	FILE *f=fopen("hangsort.txt","w");
	DocFile(&c,n,tentep);
	TongTienCuaHang(c,n);
	SapXep(c,n,f);
	MatHangThoaMan(c,n,f);
	return 0;
	
}
/*
5
Goi Keo
15000
13
But Chi
2000
20
Nuoc Ngot
11000
50
Cuc Tay
5999
10
Cuon Sach
23000
5
*/



