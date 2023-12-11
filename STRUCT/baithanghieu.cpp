#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
struct sinhvien{
	int maSV;
	char ten[30];
	float diem ;
	char truong[2];
};
// nhap n sinh vien 
void nhapSV(struct sinhvien sv[],int n){
	for (int i=1;i<=n;i++){
		printf("Thong tin sinh vien thu :%d",i);
		printf("\nNhap ten sinh vien :");
		fflush(stdin);
		fgets(sv[i].ten,sizeof(sv[i].ten),stdin);
	//	printf("\nNhap ma sinh vien:");
	//	scanf("%d",&sv[i].maSV);
		printf("\nDiem sinh vien :");
		scanf("%f",&sv[i].diem);
		printf("\nNhap truong :");
		fflush(stdin );
		fgets(sv[i].truong,sizeof(sv[i].truong),stdin);
	}
}
void inSV(struct sinhvien sv[],int n){
	for (int i=1;i<=n;i++){
	printf("\nTen sinh vien la :%s",sv[i].ten);
	printf("\nMa sinh vien la :%d",sv[i].maSV);
	printf("\nDiem sinh vien la:%.2f",sv[i].diem);
	printf("\nTruong :%s",sv[i].truong);
}
}
// tim kiem thi sinh co diem cao nhat 
void timkiem(struct sinhvien sv[],int n){
	float maxdiem=0;
	int vitri;
	for (int i=1;i<=n;i++){
		if(maxdiem<=sv[i].diem){
			maxdiem=sv[i].diem;
			vitri=i;
		}
	}
	printf("\nThi sinh co diem so cao nhat :%s",sv[vitri].ten);
	
}
//sap xep thi sinh theo diem tang dan 
void sapxep(struct sinhvien sv[],int n){
     struct sinhvien tam;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			if(sv[i].diem <=sv[j].diem){
				tam=sv[i];
				sv[i]=sv[j];
				sv[j]=tam;
			}
		}
	}
	printf("\nTen sinh vien sap xep tang dan theo diem:\n");
		for (int i=1;i<=n;i++){
		printf("\n%s",sv[i].ten);
	}
	
}
// ham so sanh sem truoc  co mat phi :s tr c m p co trong thu vien string.h
//tim kiem va in ra man hinh cac thi sinh co diem trung binh lon hon 5 cua truong B;
void search(struct sinhvien sv[],int n){
	int vitri=0;
 char ten[2]="B";
	for (int i=1;i<=n;i++){
		if(sv[i].diem > 5 && strcmp(sv[i].truong,ten)==0){
			vitri=i;
			printf("%s",sv[vitri].ten);
		}		
	}
}
// nhap vao thi sinh in ra thong tin cua sinh vien do 
void thongtin(struct sinhvien sv[],int n,char x[]){
	for (int i=1;i<=n;i++){
		if (strcmp(sv[i].ten,x)==0){
			inSV(sv,n);
		}
	}
}
//thong ke so thi sinh cua moi truong
void thongke(struct sinhvien sv[],int n){
	int dem1=0,dem2=0,dem3=0;
	char a[2]="A";
	char b[2]="B";
	char c[2]="C";// so di minh dat xau co toi da hai ki tu vi khi minh dung ham strcmp no se tinh ca \0
	for(int i=1;i<=n;i++){
		if(strcmp(sv[i].truong,a)==0){
			dem1++;
		}
	if(strcmp(sv[i].truong,b)==0){
			dem2++;
		}
		if(strcmp(sv[i].truong,c)==0){
			dem3++;
		}
	}
	printf("\nSo sinh vien truong A ,truong B, truong C lan luot la :%d %d %d",dem1,dem2,dem3);
	if(dem1>dem2 && dem1>dem3){
		printf("\nTruong A co nhieu thi sinh nhat .");
		
	}
	if(dem2>dem1 && dem2>dem3){
		printf("\nTruong B co nhieu thi sinh nhât");
		
	}
	if(dem3>dem1 && dem3>dem2){
		printf("Truong C co nhieu thi sinh nhat");
	}
}
// tim thi sinh co diem cao nhat
void diemsvmax(struct sinhvien sv[],int n){
	float max=0;
	int vitrimax;
	for (int i=1;i<=n;i++){
		if(max<sv[i].diem){
			max=sv[i].diem;
			vitrimax=i;
		}
	}
	printf("\nSinh vien co diem so max la :%s",sv[vitrimax].ten);                
}

int main (){
	int n;
	printf("Nhap n:");
	scanf("%d",&n);
	struct sinhvien sv[100];
	nhapSV(sv,n);
	// may muon chay ham nao thi tat dau"//" di
	//inSV(sv,n);
	//timkiem(sv,n);
	//sapxep(sv,n);
//	printf("\nSinh vien co diem lon hon 5 va hoc truong B la:\n");
   // search(sv,n);
   char x[30];// so di nhap x la 30 vi ham strcmp no tinh ca dau \0
   //printf("\nNhap ten :\n");
   //fflush(stdin);
   //fgets(x,sizeof(x),stdin);
   //thongtin(sv,n,x);
   thongke(sv,n);
    diemsvmax(sv,n);
	return 0;	
}