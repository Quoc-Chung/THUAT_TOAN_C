#include <stdio.h>
#include <math.h>
#include <stdlib.h>
bool nguyento (int x){
	if(x<2){
		return false ;	
	}
	else {
	for (int i=2;i<=sqrt(x);i++){
		if(x%i==0){
			return false;
		}
	}
	return true ;
}
}
void input(float *a,int n){
	for (int i=0;i<n;i++){
		scanf("%f",(a+i));//con tro tro den o nho dau tien trong mang
	}
}
void output(float *a,int n){
	for (int i=0;i<n;i++){
		printf("%.2f ",*(a+i));// gia tri cua o nho dau tien trong mang  
	}
}
void ascending (float *a,int n){
	printf("\nMang sap xep tang dan la :\n");
	for (int i=1;i<n;i++){
		for (int j=i+1;j<=n;j++){
			if(*(a+i)<*(a+j)){
				float tam=*(a+i);
				*(a+i)=*(a+j);
				*(a+j)=tam;
			}
		}
	}
	for (int i=1;i<=n;i++){
		printf("%.2f ",*(a+i));
	}
}
//int cmp (const void *a,const void *b){
//	int *x=(int *)a;
//	int *y=(int *)b;
//	return *x-*y;
//}
int cmp1(const void  *a,const void *b){
	int *x=(int *)a;
	int *y=(int *)b;
	return *y-*x;
}
void innguyento(float *a,int n){
	printf("\nCac so nguyen to la  :\n");
	for (int i=1;i<=n;i++){
		*(a+i)=(int)(*(a+i));
		if(nguyento(*(a+i))){
			printf("%.2f ",*(a+i));
		}
	}
}
void satisfy(float *a,int n,float c,float d){
	printf("\nSatisfy number :\n");
	for (int i=1;i<=n;i++){
	  if(*(a+i)>=c && *(a+i)<=d){
	  	printf("\n%f ",*(a+i));
	  }	
	}
}
void themgiatri(float *a,int &n,int vitrithem,float phantuthem){
	for (int i=n+1;i>=vitrithem+1;i--){
		*(a+i)=*(a+i-1);
	       }
		      
		*(a+vitrithem)=phantuthem ;
	    n++;	
}
void xoagiatri(float *a,int &n,int vitrixoa){
	for (int i=vitrixoa;i<=n-1;i++){
		*(a+i)=*(a+i+1);
	}
	n--;
} 
// nhap thi chay tu n+1 đến vị tri nhap +1 (cái sau lúc này bâng cai dung truoc )=>a[i]=a[i-1]
// xoa chay tu vị trí xoa đến n-1  (cái truoc duo gan cho cai sau a[i]=a[i+1]
// truyen tham chiếu & de thay doi gia tri mang   
int main (){
	int n;
	do {
		printf("\nNhap n:");
		scanf("%d",&n);
		if(n<1){
			printf("\nVui long nhap lai.\n");
		}
    }while (n<1);
    float a[100];
    input(a,n);
//    output(a,n);
//    int vitrixoa;
//    printf("\nNhap vi tri xoa :");
//    scanf("%d",&vitrixoa);
//    xoagiatri(a,n,vitrixoa);
//    innguyento(a,n);
//    float c,d;
//    printf("\nNhap giai doan :");
//    scanf("%f%f",&c,&d);
//    satisfy(a,n,c,d);
//    int vitrithem;
//    float phantuthem ;
//    printf("\nNhap vi tri them :");
//    scanf("%d",&vitrithem);
//    printf("\nNhap phantu them :");
//    scanf("%f",&phantuthem);
//    themgiatri(a,n,vitrithem,phantuthem);
    output(a,n);
//    qsort(a,n,sizeof(int ),cmp);
//    printf("\nDay sap xep tang dan la :\n");
//    for (int i=1;i<=n;i++){
//    	printf("%.2f ",a[i]);
//	}
    qsort(a,n,sizeof(int),cmp1);
    printf("\nDay sap xep tang giam dan la :\n");
    for (int i=0;i<n;i++){
    	printf("%.2f ",a[i]);
       }
//    ascending(a,n);
	return 0;
    
}
