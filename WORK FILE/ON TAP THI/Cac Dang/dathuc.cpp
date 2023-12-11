#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
// ket qua phép  cong la  :  1 -4  6 -3 -1 -11  3
// ket qua phép  trừ      :  -1  14  11 -7  -1  -1
void DocFile(int  **a,int **b,int &n,int &m,char *tentep){
	FILE *f=fopen(tentep,"r");
	if(f==NULL){
		 printf("\nKhong the mo duoc file");
	}
	fscanf(f,"%d%d",&n,&m);
	(*a)=(int *)malloc ((n+1)*sizeof(int));
	(*b)=(int *)malloc  ((m+1)*sizeof(int));
	// Doc du lieu  tu file
	for (int i=0;i<n+1;i++){
		fscanf(f,"%d",&(*a)[i]);
	}
	for(int i=0;i<m+1;i++){
		fscanf(f,"%d",&(*b)[i]);
		}
}
void GhiFile(int *a,int *b,int n,int m){
	printf("\nMang a la :");
	for(int i=0;i<n+1;i++){
		printf("%d ",a[i]);
	}
	printf("\nMang b la: ");
	for (int i=0;i<m+1;i++){
		printf("%d ",b[i]);
	}
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
void HieuHaiDaThuc(int *a, int *b, int n, int m) {
    int max = (m > n) ? (m + 1) : (n + 1);
    int *c = (int *)malloc(max * sizeof(int));
    // Thiếu kiểm tra nếu cấp số nhân của a và b không đủ để tính tới c[i]
    for (int i = 0; i < max; i++) {
        if (i > n)// i lớn hơn độ  dài của đâ thức  a thì tổng c[i] bằng  mảng  b[i] 
            c[i] = 2*b[i];
        else if (i > m)// ngược lại  
            c[i] = a[i];
        else
            c[i] = a[i] - 2*b[i];
    }
    
    printf("\nTong Hai Da Thuc:\n");
    for (int i = max - 1; i >= 0; i--) {
        printf("%d  ", c[i]);
    }  
    free(c);
}
float TinhDaThuc(int *a,int n,int x){
   float tong=(float)a[0];
	for (int i=1;i<n+1;i++){
		 tong+=(float)a[i]*pow(x,i);
	}
	return tong;
}
float TinhDaoHam(int *a, int n, int x) {
    float daoHam = (float)a[1] * 1;
    for (int i = 2; i < n + 1; i++) {
        daoHam += (float)a[i] * pow(x, i-1);  // Nhân hệ số của số hạng i với chỉ số mũ i-1
    }
    
}
int main(){
	 int n,m;
	 int *a,*b;
	 char  tentep[50]="dathuc.txt";
	 DocFile(&a,&b,n,m,tentep);
	 GhiFile(a,b,n,m);
	 TongHaiDaThuc(a,b,n,m);
	 HieuHaiDaThuc(a,b,n,m);
	 
	 int d1,d2;
	 printf("\nNhap  d1 va d2:");
	 scanf("%d%d",&d1,&d2);
	 
	 
	 float sum =sqrt(TinhDaThuc(a,n,d1)-TinhDaThuc(b,n,d2));
	 if(sum<0){
	 	printf("\nKhong the  mo duoc file.");
	 	exit(0);
	 }
	 else{
	 	printf("\nGia tri  cua da thuc la  :%.2f",sum);
	 }
	 return 0;
}