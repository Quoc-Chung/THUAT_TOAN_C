#include <stdio.h>
#include <math.h>
#include <stdlib.h>
void nhap(float *a,int n){
    for (int i=0;i<n;i++){
        scanf("%f",(a+i));
    }
}
void tong(float *a,int n){
    float tong=0;
    for(int i=0;i<n;i++){
        tong+=*(a+i);
    }
    printf("\nTong la:%.2f",tong);
}
void doi_xung(float *a,int n){
    int giua=n/2;
	int flag=0;
	for (int i=0;i<giua;i++){
		if(*(a+i)!=*(a+n-1)){
			flag++;
			break;
		}
		n--;
	}
	if(flag==0){
		printf("\nMang la mang doi xung .");
	}
	else{
		printf("\nMang khong doi xung.");
	}
}
void thong_ke(float *a,int n,float *x){
	printf("\nNhap so x:");
	scanf("%f",x);
	printf("\nCac so mang gia tri nho hon x la:\n");
	for (int i=0;i<n;i++){
		if((int)*(a+i)%2==0&& *(a+i)<*x ){
			printf("%.2f ",*(a+i));
		}
	}
}
void swap(float *a,float *b){
	float tam=*a;
	*a=*b;
	*b=tam;
}
void dao_nguoc_day(float *a,int n){
	// howjc có thể làm từ cuối đến đầu 
	int d=n;
	for (int i=0;i<d/2;i++){
		swap(&*(a+i),&*(a+n-1));
		n--;
	}
	printf("\nDay sau khi dao nguoc la :\n");
	for (int i=0;i<d;i++){
		printf("%.2f ",*(a+i));
	}
}
int cmp(const void *a,const void *b){
	float *x=(float *)a;
	float *y=(float *)b;
	if((int)*x%2==0 && (int)*y%2!=0){
		return -1;
	}
}
void sap_xep(float *a,int n){
    qsort(a,n,sizeof(float),cmp);
	printf("\nDay chan truoc le sau la :\n");
	for (int i=0;i<n;i++){
		printf("%.2f ",*(a+i));
	}
}
int main (){
    int n;
    float x;
    printf("\nNhap n:");
    scanf("%d",&n);
    float *a=(float*) malloc (n*sizeof(float));
    nhap(a,n);
   // tong(a,n);
   // doi_xung(a,n);
   // thong_ke(a,n,&x);
   // dao_nguoc_day(a,n);
    sap_xep(a,n);
    free(a);
    return 0;
}



