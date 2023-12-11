#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
void  DocFile(int **a,int &n,char *tentep){
	FILE *f=fopen(tentep,"r");
	if(f==NULL){
		printf("\nKhong the mo duoc file .");
		exit(0);
	}
	fscanf(f,"%d",&n);
	(*a) =(int *) malloc((n+1)*sizeof(int));
	for(int i=0;i<=n;i++){
		fscanf(f,"%d",&(*a)[i]);
	}
	printf("\nDa thuc trong tep la:\n");
	for(int i=0;i<=n;i++){
		printf("%d  ",(*a)[i]);
	}
}
int TongDaThuc(int *a,int n,int x){
	int value=a[0];
	for(int i=1;i<=n;i++){
		value+=a[i]*pow(x,i);
	}
	return value;
}
int TinhDaoHam(int *a,int n,int x){
	int daoham=a[1];
	for(int i=2;i<=n;i++){
		daoham+=i*a[i]*pow(x,i-1);
	}
	return daoham;
}
void TongHaiDaThuc(int *a, int *b, int n, int m) {
    int max = (m > n) ? (m + 1) : (n + 1);
    int *c = (int *)malloc(max * sizeof(int));
    // Thiếu kiểm tra nếu cấp số nhân của a và b không đủ để tính tới c[i]
    for (int i = 0; i < max; i++) {
        if (i > n)// i lớn hơn độ  dài của đâ thức  a thì tổng c[i] bằng  mảng  b[i] 
            c[i] = b[i];
        else if (i > m)// ngược lại  
            c[i] = a[i];
        else
            c[i] = a[i] + b[i];
    }
    printf("\nTong Hai Da Thuc:\n");
    for (int i = max - 1; i >= 0; i--) {
        printf("%d  ", c[i]);
    }  
    free(c);
}
// voi mot da thuc nhap  tu ban phim 
void TongHaiDaThuc(int *a,int n,int x){
	int m;
	printf("\nNhap m:");
	scanf("%d",&m);
	int *b=(int *)malloc((m+1)*sizeof(int));
	for(int i=0;i<=m;i++){
		scanf("%d",&b[i]);
	}
	int Tong=TongDaThuc(a,n,x)+TongDaThuc(b,m,x);
	printf("\nTong hai da thuc la  :%d",Tong);
}
int main (){
	int n;
	int *a;
	char tentep[50]="dathuc.txt";
	DocFile(&a,n,tentep);
	
	int x;
	printf("\nNhap  gia tri x:");
	scanf("%d",&x);
	
	TongHaiDaThuc(a,n,x);
	
}
