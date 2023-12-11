#include <stdio.h>
#include <math.h>
struct diem {
	int  hoanh;
	int tung;
};
void nhap(struct diem d[],int n){
	printf("\nNhap diem :");
	for (int i=1;i<=n;i++){
		printf("\n Diem thu %d:",i);
		scanf("%d%d",&d[i].hoanh,&d[i].tung);
	}
}
void in( diem d[],int n){
	for (int  i=1;i<=n;i++){
		printf("\nDiem thu %d:(%d,%d)",i,d[i].hoanh,d[i].tung);
	}
}
void demdiem( diem d[],int n){
         int dem=0;
	printf("\nCac diem nam trong duong tron :\n");
	for (int i=0;i<n;i++){
		if((pow(d[i].hoanh,2)+pow(d[i].tung,2))<(7.5*7.5)){
			printf("\n%d %d",d[i].hoanh,d[i].tung);
			dem++;
		}
	}
	printf("\nVay co tat ca %d diem nam trrong duong tron.",dem);
}

int main (){
	int  n;
	printf("\nNhap so diem :");
	scanf("%d",&n);
	diem d[100];
	nhap(d,n);
	in(d,n);
	demdiem(d,n);
	return 0;
}