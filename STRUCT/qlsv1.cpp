#include <stdio.h>
#include <math.h>
#include <string.h>
void xoaxuongdong(char c[]){
	size_t len=strlen(c);
	if(c[len-1]='\n'){
		c[len-1]='\0';
	}
}
struct diem {
	float monA;
	float monB;
	float monC;
};
struct sinhvien  {
	char ten[30];
	diem mon;
};
void input (sinhvien *sv){
	printf("\nNhap ten sinh vien :");
	fflush(stdin);
	fgets(sv->ten,sizeof(sv->ten),stdin);
	printf("\nNhap diem cac mon :\n");
	printf("\nMon A:");
	scanf("%f",&sv->mon.monA);
	printf("\nMon B:");
	scanf("%f",&sv->mon.monB);
	printf("\nMon C:");
	scanf("%f",&sv->mon.monC);
}
float tongdiem (float a,float b,float c){
	 float tong=a+b+c;
	 return tong;
}
// in ra danh sach tong diem sinh vien duoi dang mang mot chieu ;
void danhsach(sinhvien sv[],int n){
	printf("\n\t\t\tDANH SACH TONG DIEM :\n");
	printf("\n%-20s %-8s","Ho va ten","Tong diem\n");
	for (int i=1;i<=n;i++){
		xoaxuongdong(sv[i].ten);
		printf("\n%-20s %-8.2f",sv[i].ten,tongdiem(sv[i].mon.monA,sv[i].mon.monB,sv[i].mon.monC));
	}
}
void diemtongtangdan(sinhvien sv[],int n){
	float diemtong;
	sinhvien tam;
	// dau lon hon ch? s? tang dan ,d?u nh? hon chi su giam dan 
	for (int i=1;i<=n;i++){
		for (int j=i+1;j<=n;j++){
		if (tongdiem(sv[i].mon.monA,sv[i].mon.monB,sv[i].mon.monC) >
         tongdiem(sv[j].mon.monA,sv[j].mon.monB,sv[j].mon.monC)){
				tam=sv[i];
				sv[i]=sv[j];
				sv[j]=tam;
			}
		}
	}
	printf("\nDanh sach sinh vien co tong diem tang dan la :\n");
	for (int i=1;i<=n;i++){
		printf("\n%s",sv[i].ten);
	}
}
void inputmuch(sinhvien *sv,int n){
	for (int i=1;i<=n;i++){
		printf("\nSinh vien thu %d :",i);
		input (sv+i);
	}
}
void outputtable(sinhvien sv[],int n){
	printf("\n\t\t\tBANG THONG TIN :\n");
	printf("%-20s %-9s %-9s %-9s","Ho va ten","Mon A","Mon B","Mon C\n");
	for (int i=1;i<=n;i++){
		xoaxuongdong(sv[i].ten);
		printf("\n%-20s %-9.2f %-9.2f %-9.2f",sv[i].ten,sv[i].mon.monA,sv[i].mon.monB,sv[i].mon.monC);
	}
}
void themsinhvien(sinhvien *sv,int &n,int vitrithem){
	for (int i=n+1;i>=vitrithem+1;i--){
		*(sv+i)=*(sv+i-1);
	}
	n++;
	input(sv+vitrithem);
}
int main (){
	int n;
	printf("\nNhap n:");
	scanf("%d",&n);
	sinhvien sv[100];// ban chat sinh vien luc nay cung la mot con tro vi no luu dia chi cua o nho dau tien trong mang  
	inputmuch(sv,n);
	int vitrithem;
	printf("\nNhap vi tri them:");
	scanf("%d",&vitrithem);
	themsinhvien (sv,n,vitrithem);
    danhsach (sv,n);
    diemtongtangdan(sv,n);
	outputtable (sv,n);
	return 0;
}