#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
void  Doc(int **a,int &n, char *tentep) {
	FILE *f = fopen(tentep, "r");
	if (f == NULL) {
		printf("\nKhong the doc duoc file");
		exit(1);
	}
	fscanf(f, "%d", &n);

	*a = (int *)malloc((n + 1) * sizeof(int));
	if (*a == NULL) {
		printf("\nKhong the mo duoc file.");
		exit(1);
	}

	for (int i = 0; i < n + 1; i++) {
		fscanf(f, "%d", &(*a)[i]);
	}

	printf("\nHe so da thuc duoc doc tu file la:\n");
	for (int i = 0; i < n + 1; i++) {
		printf("%d ", (*a)[i]);
	}

	fclose(f);
}
int x;
void GiaTriDaThuc (int  *a,int n){
	int result=a[0];
		
	printf("\nNhap gia tri x :");
	scanf("%d",&x);
	for (int i=1;i<=n;i++){
		result +=a[i]*pow(x,i);
	}
	printf("\nGia tri cua da thuc  la  :%d",result );
}
void DaoHam (int *a,int n){
	int daoham=a[1];
	for (int i=2;i<=n;i++){
		daoham  += i*a[i]*pow(x,i-1);
	}
	printf("\nGia tri cua dao ham la : %d", daoham);
}
void CongHaiDaThuc(int *a, int n) {
	// Nhap  thong tin cua da thuc  can cong voi  da thuc a ;
	int m;
	printf("\nNhap da thuc b: ");
	scanf("%d", &m);
	int b[m];
	for (int i = 0; i < m; i++) {
		scanf("%d", &b[i]);
	}

//	kiem tra xem trong  hai c da thuc thi da thuc nao co do dai lon hon thi  se luu  ket qua vao  da thuc co chieu dai  lon hon 
	if (n > m) {// da thuc  a  co  do  dai lon hon 
		for (int i = 0; i < n; i++) {
		
			if (i < m){// Cong he so cua da thuc a vao da thuc  b cho den khi khong con ket qua nua thi dung  lai  
				a[i] += b[i];// ket qua duoc  luu  vao  bieu  thuc a 
			}
		}
		// truong hop nay da thuc  b co chieu  dai lon hon  da thuc   a  
	} else {
	//	chay vong for chua chieu dai cua da thuc  b
		for (int i = 0; i < m; i++) {
			// chay den khi nao bieu thuc a het  he so thi dung  lai 
			if (i < n) {
				b[i] += a[i];
			}
		}

		// cap nhat  ket qua  vao mang a  co nghia la  neu ma  m lon hon n thi ket qua  chya tu  0 den m  se duoc cap nhat  vao mang a  
		for (int i = 0; i < m; i++) {
			a[i] = b[i];
		}
		n=m;
	}
	printf("Ket qua: ");
		for (int i=n;i>=0;i--){
			printf("%d*x^%d",a[i],i);
			if(i>0){
				printf("+");
			}
	}
	
}
// hàm này  tính  tổng  hai  đa thức  có x  dược  nhập  từ  bàn  phím  
void TongHaiDaThuc(int *a,int n){
	int m;
	printf("\nNhap da thuc b: ");
	scanf("%d", &m);
	int b[m];
	for (int i = 0; i < m; i++) {
		scanf("%d", &b[i]);
	}
	int tongb=0,tonga=0;
	x=3;
	for(int i=0;i<m;i++){
		tongb+=b[i]*pow(x,i);
	}
	for(int i=0;i<n;i++){
		tonga+=a[i]*pow(x,i);
	}
	int tong=tonga+tongb;
	printf("Tong P(3)+Q(3) la : %d",tong);
}
int main() {
	int n;
	int *a;
	char tentep[50] = "dathuc1.txt";
    Doc(&a,n, tentep);
	GiaTriDaThuc (a,n);
	 DaoHam (a,n);
	 CongHaiDaThuc(a,n );
	 TongHaiDaThuc(a,n);
	return 0;
}