#include <stdio.h>
#include <math.h>
#include <string.h>
void xoaxuongdong (char c[] ){
  size_t len= strlen (c);
  if(c[len-1]=='\n'){
	c[len-1]='\0';
   }
}
void xuongdong(){
	printf("\n");
}
struct mathang {
int stt;
char ten[40];
char nhomhang[30];
 float giamua,giaban;
 };
 void nhap (mathang mh[],int n){
 	for (int i=1;i<=n;i++){
 		mh[i].stt=i;
 		fflush(stdin);
 		fgets(mh[i].ten,sizeof(mh[i]),stdin);
 		fflush(stdin);
 		fgets(mh[i].nhomhang,sizeof(mh[i].nhomhang),stdin);
 		scanf("%f%f",&mh[i].giamua,&mh[i].giaban);
	 }
 }
 void nhap_bang_con_tro(mathang *mh,int n){
 	for (int i=1;i<=n;i++){
 		mh->stt=i;
 		fflush(stdin);
 		fgets(mh->ten,sizeof(mh->ten),stdin);
 		fflush(stdin);
 		fgets(mh->nhomhang,sizeof(mh->nhomhang),stdin);
 		scanf("%f%f",&mh->giamua,&mh->giaban);
	 }
 }
 
   float loinhuan (long long giamua,long long giaban){
 	long long loinhuan=giaban-giamua;
 	return loinhuan;
 }
 void information (mathang mh[],int n){
 	mathang tam;
 	for (int i=1;i<n;i++){
 		for (int j=i+1;j<=n;j++){
 		if(loinhuan(mh[i].giamua,mh[i].giaban)>loinhuan(mh[j].giamua,mh[i].giaban)){
 			tam =mh[i];
 			mh[i]=mh[j];
 			mh[j]=tam;
		 }
	 }
 }
 for(int i=1;i<=n;i++){
  xoaxuongdong(mh[i].ten);
  xoaxuongdong(mh[i].nhomhang);
 printf("\n%d %s %s %.2f",mh[i].stt,mh[i].ten,mh[i].nhomhang,loinhuan(mh[i].giamua,mh[i].giaban));
     }
}
int main (){
	int n;scanf("%d",&n);
	mathang mh[100];
//	nhap(mh,n);
// mh là địa chỉ của biến đầu tiên trong mảng
 nhap_bang_con_tro(mh,n);
	information (mh,n);
	return 0;
}