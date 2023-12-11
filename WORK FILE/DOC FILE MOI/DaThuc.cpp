#include<stdio.h>
#include<math.h>
#include<stdlib.h>
// Đọc hệ số của đa thức a 
void DocFile(float **a,int *n,char *tentep){
	FILE *f;
	f=fopen(tentep,"r");
	if(f==NULL){
		printf("\nKhong the mo duoc file .");
		exit(0);
	}
	fscanf(f,"%d",n);
	*a=(float *) malloc (*n *sizeof(float));
	if(*a==NULL){
		printf("\nKhong cap phat duoc bo nho dong.");
		exit(0);
	}
	for(int i=0;i<=*n;i++){
		fscanf(f,"%f",(*a+i));// *a gio se cung voi a tro toi phan tu dau cua mang
	}
}
// in ra  file  vừa  đọc  
void File(float *a,int n){
	printf("\nMang  duoc doc tu file la:\n");
	for(int i=0;i<=n;i++){
		printf("%.2f ",*(a+i));
	}
}
// giá trị của đa thức
void TinhGiaTriDaThuc(float*a,int n,float &x){
	printf("\nNhap gia tri x de tinh gia tri:");
	scanf("%f",&x);
	float Value=a[0];
	for(int i=1;i<=n;i++){
		Value+=a[i]*pow(x,i);
	}
	printf("\nGia tri cua da thuc la :%.2f",Value);
}

float GiaTriDaThuc(float*a,int n,float &x){
	float Value=a[0];
	for(int i=1;i<=n;i++){
		Value+=a[i]*pow(x,i);
	}
	return Value;
}
void DaoHam(float*a,int n,float &x){
	printf("\nNhap gia tri x de tinh dao ham :");
	scanf("%f",&x);
	float Value=a[1];
	for(int i=1;i<=n;i++){
		Value+=i*a[i]*pow(x,i-1);
	}
	printf("\nDao Ham cua da thuc la:%.2f",Value);
}
void TongHaiDaThuc(float *a,float *b,int n,int &m,float &x1,float &x2){
	printf("\nNhap x1:");
	scanf("%f",&x1);
	
	printf("\nNhap x2:");
	scanf("%f",&x2);
	
	printf("\nNhap m:");
	scanf("%d",&m);
	
	b=(float *) malloc (100*sizeof(float));
	if(b==NULL){
		printf("\nKhong cap phat duoc bo nho dong.");
		exit(0);
	}
	printf("\nNhap he so da thuc b :\n");
	for(int i=0;i<=m;i++){
		scanf("%f",(b+i));
	}
	float Sum=GiaTriDaThuc(a,n,x1) + GiaTriDaThuc(b,m,x2);
	printf("\nTong hai da thuc la:%.2f",Sum);
	free(b);
}
int main(){
	float *a,*b;
	int m,n;
	char tentep[50];
	printf("\nNhap ten tep :");
	gets(tentep);
	DocFile(&a,&n,tentep);
	File(a,n);
	float  x, x1,x2;
	TinhGiaTriDaThuc(a,n,x);
	DaoHam(a,n,x1);
	TongHaiDaThuc(a,b,n,m,x1,x2);
	return 0;
}