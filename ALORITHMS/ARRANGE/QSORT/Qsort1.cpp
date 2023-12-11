// ham sap xep phai chay tu 0 den n
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
int tongchuso(int n){
	int tong=0;
	while (n>0){
		tong +=n%10;
		n/=10;
	}
	return tong;
}
void nhapmang(int a[],int n){
	for (int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
}
//1.Sap xep tang dan
int cmp(const void *a,const void *b){
	int *x=(int*)a;
	int *y=(int*)b;
	if(*x<*y)// dung gia tri ma con tro tro toi 
      return -1;
      else
      return 1;      
}
int cmp1(const void *a,const void *b){
	int *x=(int *)a;
    int *y=(int *)b;
    return *x-*y;
}
//2.Sap xep giam dan :
int cmp3(const void *a,const void *b){
	int *x=(int *)a;
	int *y=(int *)b;
	//if(*x<*y)// tuc la a nhỏ hon b thì a xếp sau.
//	{
	//	return 1;
	//}
//	else {
//		return -1;
	//}
	return *y-*x;
	
}
//3.Sắp xếp theo tri tuyệt đối tưng dần .
 int cmp4(const void *a,const void *b){
	int *x=(int *)a;
	int *y=(int *)b;
	if(abs(*x)<abs(*y)){ // tức nếu trị tuyệt đối của a<trị tuyệt đố b=> sắp xếp a trước 
		return -1;
	}
	else {
		return 1;
	}
//	return abs(*x)-abs(*y);
}
//4.sắp xếp theo tổng các chữ số tăng dần 
int cmp5(const void *a,const void *b){
	int *x=(int *)a;
	int *y=(int *)b;
	if(tongchuso(*x)!=tongchuso(*y)){
	return tongchuso(*x)-tongchuso(*y);// ta sap xep theo chu so truoc 
}
	if(*x<*y){// ta xet gia tri de sap lai not gia tri
	// tuc la so a nho hon so b thì sếp số a trước 
		return -1;
	
}
}
//5.Sap xep sao cho so chan xep truoc ,so le xep sau
int cmp6(const void *a,const void *b){
	int *x=(int *)a;
	int *y=(int *)b;
	if(*x%2==0 && *y%2==1){
	 return -1;
    }
    else {// nguoc lai tuc la neu *x lẻ và *y chẫn thì xếp *x sau(return 1)
     return 1;
}	
}
//6.Sap xep sao cho so chan dung truoc va giam dan,so le dúng sau va tang dan
int cmp7(const void *a,const void *b){
	int *x=(int *)a;
	int *y=(int *)b;
	if(*x%2==0 && *y%2==1){
	 return -1;
    }
    else {// nguoc lai tuc la neu *x lẻ và *y chẫn thì xếp *x sau(return 1)
     return 1;
 }
    if (*x%2==0 && *y%2==0){
    	return *y-*x;
			}
	if(*x%2==1 && *y%2==1){
		return *x-*y; 
	}
	
}
//7.Sắp xếp số nguyên tố xếp trước và có giá trị tăng dần 
bool nguyento(int n){
	if(n<2) {
	return false;
}
	else {
		for(int i=2;i<=sqrt(n);i++){
			if(n%i==0)
			return false;
		}
	}
	return true;
}
//testcase:1 3 6 5 9 7 4=>>   3 5 7     9 6 4 1
int cmp8(const void *a,const void *b){
	int *x=(int *)a;
	int *y=(int *)b;
	// sap xep nguyen to dung truoc 
	if(nguyento(*x)==true && nguyento(*y)==false){
		return -1;// cho so x xếp trước neu so x la so nguyen to 
	}
	else if (nguyento(*x)==false && nguyento(*y)==true){//neu x khong la so nguyen to thi ta xep x o phia sau
		return 1;
	}
	// sap xep cac so nguyenn to giam dan
	if(nguyento(*x)==true && nguyento(*y)==true){
	 return *y-*x;
	}
	// sap xep khong la nguyen to phia sau tang dan
	if(nguyento(*x)==false && nguyento(*y)==false){
		return *x-*y;
	}
}
int main (){
	int n;
	printf("Nhap n:");
	scanf("%d",&n);
	int a[n];
	nhapmang(a,n);
	qsort (a,n,sizeof(int),cmp8);
	printf("Mang vua xep la :\n");
		for (int i=0;i<n;i++){
		printf("%d ",a[i]);
	}
}