#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
struct  Diem{
	int  hoanh;
	int tung;
};
void  DocFile(Diem **d,int  &n,char  *tentep){
	FILE*f=fopen(tentep,"r");
	if(f==NULL){
		printf("\nKhong the  mo duoc file.");
		exit(0);
	}
	fscanf(f,"%d",&n);
	(*d)=(Diem*)malloc (n*sizeof(Diem));
	for(int i=0;i<n;i++){
		fscanf(f,"%d%d",&(*d)[i].hoanh,&(*d)[i].tung);
	}
	printf("\nDay diem vua doc tu  file  la  :\n");
	for(int  i=0;i<n;i++){
	  printf("\n %d %d ",(*d)[i].hoanh,(*d)[i].tung);	
	}
}
//  diem  ngoai  duong tron
void  Diem (Diem *d,int n){
	int dem=0;
	for(int i=0;i<n;i++){
		if(sqrt(pow(d[i].hoanh,2)+pow(d[i].tung,2)) < 5){
			dem++;
		}
	}
	if(dem>0){
			printf("\Co %d  diem  nam  ngoai  duong  tron.",dem);
	}
	else{
		printf("\nKhong co  diem  nao  nam  ngoai  duong tron.");
	}
}
int GiaiThua(int n) {
    if (n <= 1)
        return 1;
    else
        return n * GiaiThua(n - 1);
}
// Hàm tính tổ hợp chập k của n
int TinhToHop(int n, int k) {
    int tohop = GiaiThua(n) / (GiaiThua(k) * GiaiThua(n - k));
    return tohop;
}
// đếm  số  đoạn  nằm trong  đường tròn bán kính là  5 
void DoanTrong (Diem *d,int n){
	int dem=0;
	for(int i=0;i<n;i++){
	float distance = sqrt(pow(d[i].hoanh, 2) + pow(d[i].tung, 2));
	if(distance < 5){
		dem++;
	}
	}
	printf("\nSo doan Thang  nam trong  duong tron ban kinh bang 5 la :%d",TinhToHop(dem,2))
}
int  main (){
	int n;
	Diem *d;
	char tentep[50]="bai1.txt";
	DocFile(&d,n,tentep);
	DoanTrong (d,n);
	return 0;
}