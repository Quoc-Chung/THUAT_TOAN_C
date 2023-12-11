#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
struct  Diem {
	int  hoanh;
	int tung ;
};
void DocFile (Diem **d,int &n,char *tentep){
	FILE *f=fopen(tentep,"r");
	if(f==NULL){
		printf("\nKhong the  mo duoc file.");exit(0);
	}
	fscanf(f,"%d",&n);
	(*d)=(Diem *) malloc (n*sizeof(Diem));
	for  (int i=0;i<n;i++){
		fscanf(f,"%d%d",&(*d)[i].hoanh,&(*d)[i].tung);
	}
	printf("\nThong tin toa do la  :\n");
	for (int  i=0;i<n;i++){
		printf("\n( %d , %d )",(*d)[i].hoanh,(*d)[i].tung);
	}
}
// Xác định  điểm  ở  xa  tọa độ nhất  
void  DiemXaToaDo(Diem *d,int n){
	int  h,t;
	float  max=-1e8;
	for (int i=0;i<n;i++){
	   if(max < sqrt(pow(d[i].hoanh,2)  + pow( d[i].tung,2) ) ){
	   	max=sqrt(pow(d[i].hoanh,2)  + pow( d[i].tung,2) ) ;
	   	h=d[i].hoanh;
	   	t=d[i].tung;
	   }
	}
	printf("\nDiem Xa Toa Do Nhat:( %d , %d )",h,t);
}
// 2 diem  noi  voi nhau  tao  thanh  mot  doan thang.  
// goc phan tu  thu 1 :  (hoành +  , tung  + )
// goc  phan  tu thu  2: (hoành -  , tung  + )
// goc  phan tu thu  3:  (hoanh -  , tung  - )
// goc  phan  tu thu  4 :(hoanh +  , tung  - )
int GiaiThua(int n) {
	if (n == 1) {
		return 1;
	}
	return n * GiaiThua(n - 1);
}
int ToHop(int k, int n) {
    int ToHop = GiaiThua(n) / (GiaiThua(n - k) * GiaiThua(k));
    return ToHop;
}
void SoDoanThang (Diem *d,int n){
	int dem=0;
	for  (int i=0;i<n;i++){
		if(d[i].hoanh < 0 && d[i].tung<0 ){
			dem++;
		}
	}
	if(dem<=1){
		printf("\nKhong co  doan thang  nao.");
	}
	else {
		printf("\nCo  %d doan thang trong goc  phan tu  thu  3.",ToHop(2,dem));
	}
}
// Hàm  tìm  đoạn  thẳng dài nhất 
void TimDoanThangDaiNhat(Diem *d, int n) {
	float kcMax= 0;
	int vtDiem1 = 0, vtDiem2 = 0;
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			float  KhoangCach =sqrt(pow(d[j].hoanh - d[i].hoanh,2) + pow(d[j].tung - d[i].tung,2));
			if (kcMax  <   KhoangCach) {
				kcMax=KhoangCach;
				vtDiem1 = i;
				vtDiem2 = j;
			}
		}
	}
	printf("\nDoan thang dai nhat:(%d, %d) - (%d, %d)", d[vtDiem1].hoanh, d[vtDiem1].tung, d[vtDiem2].hoanh, d[vtDiem2].tung);
}
// đếm  số điểm  thuộc  đường  phân giác  ở góc phần tư thứ nhất  
void  DiemGoc(Diem *d,int n){
	int dem=0;
	for  (int i=0;i<n;i++){
		if( d[i].hoanh  > 0  &&d[i].tung && d[i].hoanh ==d[i].tung){
			dem++;
		}
	}
	if (dem >0 ){
			printf("\n So  diem  thoa  man la  : %d ",dem);
	}
	else  {
		printf("\nKhong co diem nao thoa  man .");
	}
}
int  main (){
	int  n;
	Diem *d;
	char  tentep[50]="ToaDo.txt";
	DocFile(&d,n,tentep );
	DiemXaToaDo(d,n);
	SoDoanThang (d,n);
	TimDoanThangDaiNhat(d,n);
	DiemGoc(d,n);
	return 0;
	
}