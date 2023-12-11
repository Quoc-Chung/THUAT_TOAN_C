#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// cac lam dang bai nay thi thuong co 4 truong hop 
// tang dân  return *x-*y;
// giamdan   return *y-*x;
// dungtruoc return -1;
//  dungsau  return 1;
// sap xep cac so nguuyento co trong mảng theo hướng giảm dần
int nguyento(int n){
	if(n<2) {
	return 0;
}
	else {
		for(int i=0;i<=sqrt (n);i++){
			if(n%i==0)
			return 0;
		}
	}
	return 1;
}

int tongchuso(int n){
	int sum =0;
	while(n>0){
		sum+=n%10;
		n/=10;
	}
	return sum;;
}
void  nhapmang(int a[],int n){
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
}
void inmang(int a[],int n){
	for (int i=1;i<=n;i++){
		printf("%d ",a[i]);
			}
}
// sap xep so chan xep truoc theo thu tu giam dan ,so le xep sau theo thu tu tang dan 
int comparetor(const void *a,const void *b){// truyen vao hai bien con tro 
	int *x=(int *)a;// gan bien con tro theo kieu du lieu cua bien mang khai bao o ham chinh
	int *y=(int *)b;
	if(*x%2==0  && *y%2==1){ // x la so chan va y la so le 
	return -1;// so x xep truoc so y hay so chan xep truoc so le 
}
	if(*x%2==1  && *y%2==0) {
	return 1;// so x xep sau so y hay so chan xep truoc so le 
}
	if(*x%2==0 && *y%2==0){
	 return *y - *x;// tuc la giua hai so chan thi ta se sap xep giam dan
}
    else {
	return *x-*y; // nguoc lai vơi cac phan phia tren 
}  
}

// sap xep tang dan tuc voi a va b nếu a nhỏ hơn thì sẽ đứng trước 
int comparetor1(const void *a ,const void *b){
	int *x=(int *)a;
	int *y=(int *)b;
	if(*x<*y )return *x-*y; // thuan chieu thi tang dan 
// sap xep giam dan thi *y-*x	
}
// sap xep theo tri tuyet doi tang dan 
int comparetor2(const void *a ,const void *b){
	int *x=(int *)a;
	int *y=(int *)b;
     return abs(*x)-abs(*y);// tri tuyet doii tang dan no cung giong nhu so tang dan *x-*y
}
//sap xep theo tri tuyet dôi tang dan,neu 2 so do co cùng tri tuyet doi thi so duong duoc xep sau
int comparetor3(const void *a ,const void *b){
	int *x=(int *)a;
	int *y=(int *)b;
     if(abs(*x)<abs(*y)) return abs(*x)-abs(*y);
     if(*x>0) return 1;
}
// sap xep theo tong cac chu so tang dan
int comparetor3(const void *a ,const void *b){
	int *x=(int *)a;
	int *y=(int *)b;
     if(tongchuso(*x)<tongchuso(*y)) {//  tuc la so x có tong nho hon so y 
     	return -1;
	 }
	 // cach khac ta return tongchuso(*x)-tongchuso(*y) tuc la sap xep tang dan 
	 return 1;
}
// sap xeptheo tong chu so tang dan neu hai so có cùng tong chu so thì in số có giá trị nhỏ hơn ra phía sau
int comparetor4(const void *a ,const void *b){
	int *x=(int *)a;
	int *y=(int *)b;
     if(tongchuso(*x)!= tongchuso(*y)){
     	return tongchuso(*x)-tongchuso(*y);
	 }
	 if(*x<*y){
	 	return 1;
	 }
}
int main (){
	int n;
	printf("So phan tu mang :");
	scanf("%d",&n);
	int a[n];
	nhapmang(a,n);
	printf("Mang truoc khi sap xep :\n");
	inmang(a,n);
	printf("Cac so nguyen to trong mang:\n");
	printf("\nMang sau khi sap xep la :\n");
	qsort (a,n,sizeof(int),comparetor);
		for (int i=1;i<=n;i++){
		printf("%d ",a[i]);
			}
}

