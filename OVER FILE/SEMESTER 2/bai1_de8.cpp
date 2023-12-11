#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
struct diem{
	int hoanh;
	int tung;
};
void nhap_diem_tu_toa_do(diem d[],int &n){
	FILE *f;
	char duong_dan[100]="C:\\Users\\Admin\\Documents\\THUATTOANC\\WORD FILEC\\bai1_de8.txt";
	f=fopen(duong_dan,"r");
	if(f==NULL){
		printf("\nKhong the lay phan so tu file.");
		exit(1);
	}
	fscanf(f,"%d",&n);
	for (int i=1;i<=n;i++){
		fscanf(f,"%d %d\n",&d[i].hoanh,&d[i].tung);
	}
	fclose (f);
}
void in_cac_diem (diem d[],int n){
	printf("+-------------------+\n");
	printf("|  DANH SACH DIEM   |\n");
	printf("+-------------------+\n");
	for (int i=1;i<=n;i++){
	printf("|    (%-2d ,%-2d)       | \n",d[i].hoanh,d[i].tung);
	}
	printf("+-------------------+\n");
}
// hoanh*hoanh + tung*tung < r
int cac_diem_nam_trong_duong_tron(diem d[],int n){
	int hoanh,tung,dem=0;
	printf("\nCac diem thoa man la :\n");
	for (int i=1;i<=n;i++){
		hoanh=0,tung=0;
		if(d[i].hoanh*d[i].hoanh+d[i].tung*d[i].tung < 5*5){
			hoanh=d[i].hoanh;
			tung=d[i].tung;
			dem++;
			printf("(%d,%d)\n",d[i].hoanh,d[i].tung);
		}
		
	}
	printf("\n==>Co tong so %d thoa man.",dem);	
	return dem;	
}
void do_dai_gap_khuc(diem d[],int n){
	float do_dai=sqrt(pow(d[1].hoanh-d[n].hoanh,2)+pow(d[1].tung-d[n].tung,2));
	for (int i=2;i<n;i++){
		do_dai+=sqrt(pow(d[i+1].hoanh-d[i].hoanh,2)+pow(d[i+1].tung-d[i].tung,2));
	}
	printf("\nDo dai duong gap khuc la :%.2f",do_dai);
}
void doan_thang_trong_duong_tron(diem d[],int n){
	int dem=cac_diem_nam_trong_duong_tron(d,n);
	printf("\nSo doan thang trong duong tron la :%d",dem/2);
}
int main (){
	int n;
	diem d[MAX];
	nhap_diem_tu_toa_do(d,n);
	in_cac_diem (d,n);
	cac_diem_nam_trong_duong_tron(d,n);
	do_dai_gap_khuc(d,n);
	doan_thang_trong_duong_tron(d,n);
	return 0;
}