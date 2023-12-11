#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<stdlib.h>
struct Diem{
	int hoanh;
	int tung;
};
void  DocFile(Diem **d,int &n,char *tentep ){
	FILE *f=fopen(tentep,"r");
	if(f==NULL){
		printf("\nKHong the  mo duoc file.");
		exit(0);
	}
	fscanf(f,"%d",&n);
	(*d)=(Diem *) malloc (n*sizeof(Diem));
	for (int i=0;i<n;i++){
		fscanf(f,"%d%d",&(*d)[i].hoanh,&(*d)[i].tung);
	}
	printf("\nDay  diem  tu file la  :\n");
	for (int i=0;i<n;i++){
			printf("\n%d %d",(*d)[i].hoanh,(*d)[i].tung);
	}
}
void  DiemKhac(Diem *d,int n){
	int  h1=0,t1=0;
	float min=INT_MAX;
	bool  check=false;
	for(int i=0;i<n;i++){
			if((d[i].hoanh +d[i].tung)%2!=0 && min>sqrt(pow(d[i].hoanh,2) +pow(d[i].tung,2))){
				min=sqrt(pow(d[i].hoanh,2) +pow(d[i].tung,2));
				h1=d[i].hoanh;t1=d[i].tung;
				check=true;
		}
	}
	if(check){
		
		printf("\nDiem can  tim la :%d %d",h1,t1);
	}
	else {
		printf("\nKhong  co diem  can tim.");
	}		
}
void kcMin(Diem* d, int n) {
	int khoangcachmin = INT_MAX;
	int h1 = 0, t1 = 0, h2 = 0, t2 = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int khoangcach = abs(d[i].hoanh - d[j].hoanh) + abs(d[i].tung - d[j].tung);
			if (khoangcach < khoangcachmin) {
				khoangcachmin = khoangcach;
				h1 = d[i].hoanh;
				t1 = d[i].tung;
				h2 = d[j].hoanh;
				t2 = d[j].tung;
			}
		}
	}
	printf("\nTat ca cac doan thang co khoang cach Manhattan nho nhat la:");
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int khoangcach = abs(d[i].hoanh - d[j].hoanh) + abs(d[i].tung - d[j].tung);
			if (khoangcach == khoangcachmin) {
				printf("\n%d %d    %d %d", d[i].hoanh, d[i].tung, d[j].hoanh, d[j].tung);
			}
		}
	}
}
int  main (){
	int n;
	Diem *d;
	char tentep[50]="diem.txt";
	DocFile(&d,n,tentep);
	DiemKhac(d,n);
	kcMin(d,n);
	return 0;
}