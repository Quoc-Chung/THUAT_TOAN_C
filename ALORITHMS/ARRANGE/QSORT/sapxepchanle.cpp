#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
// mang phai chay tu o den n
void nhapmang(int a[],int n){
	for (int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
}
void inmang(int a[],int n){
	for (int i=0;i<n;i++){
		printf("%d ",a[i]);
	}
}
int cmp(const void *a,const void *b){
int *x=(int *)a;
int *y=(int *)b;
// Sắp xếp số chẵn trước số lẻ
if(*x % 2 == 0 && *y % 2 != 0)
return -1;
else if (*x % 2 != 0 && *y % 2 == 0)
return 1;
// Sắp xếp hai số chẵn tăng dần
if(*x % 2 == 0 && *y % 2 == 0)
return (*x-*y);
if(*x%2==1 && *y%2==1)
return (*x-*y);

}
// sap xep so chân tang dan so le giam dan và chẵn xếp trước số lẻ 

int cmp1(const void *a,const void *b){
	int *x=(int *)a;
	int *y=(int *)b;
	if(*x%2==0 && *y%2!=0 )
		return -1;
	else if(*x%2!=0 && *y%2==0)
	return 1;
	
	if(*x%2== 0 && *y%2== 0 )
		return (*x-*y);
		
	else if(*x%2!=0 && *y%2!=0)
	return (*y-*x);
}
// số le %2!=0 
// so chan %2==0 
int main (){
	int n;
	scanf("%d",&n);
	int a[n];
	nhapmang(a,n);
	qsort (a,n,siz
	eof(int),cmp1);
	inmang(a,n);
	return 0;
}