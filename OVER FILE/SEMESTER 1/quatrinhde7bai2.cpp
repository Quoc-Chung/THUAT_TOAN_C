
//- Kiểm tra xem ma trận có đối xứng qua đường chéo chính hay không.
 //Tìm giá trị lớn nhất của từng hàng.
// Tính trung bình cộng các giá trị dương của ma trận.
#include <stdio.h>
#include <math.h>
void nhapmang(float a[100][100],int m,int n){
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			printf("Nhap gia tri a[%d][%d]:",i,j);
			scanf("%f",&a[i][j]);
		}
	}
}
void inmang (float a[100][100],int m,int n){
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			
		printf("%.2f ",a[i][j]);
	}
	printf("\n");
}
}
//- Kiểm tra xem ma trận có đối xứng qua đường chéo chính hay không.
void doixungcheochinh(float a[100][100],int m,int n){
	int flag=0;
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			if(a[i][j]==a[j][i]){
				flag=0;
			}
			if(a[i][j]!=a[j][i]){
				flag=1;
				break;
			}
		}
	}
	if(flag==0){
		printf("\nDoi xung ");
	}
	if(flag==1){
		printf("\nKhong doi xung ");
	}
	
}
// kiemtra doi xung qua duong cheo phu
void doixungcheophu(float a[100][100],int m,int n){
	int flag=0;
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			if(a[i][j]==a[n-1-j][n-1-i]){
				flag=0;
			}
			if(a[i][j]!=a[n-1-j][n-1-i]){
				flag==1;
				break;
			}
		}
	}
	if(flag==0){
		printf("\nDoi xung ");
	}
	if(flag==1){
		printf("\nKhong doi xung ");
	}
	
}
float trungbinhcong(float a[100][100],int m,int n){
	int dem=0;
	float s=0;
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			if(a[i][j]>0){
				s+=a[i][j];
				dem++;
			}
		}
	}
	return s/(1.0*dem);
}
int main (){
	int m,n;
	printf("Nhap kich thuoc :");
	scanf("%d%d",&m,&n);
	float a[100][100];
	nhapmang(a,m,n);
	inmang(a,m,n);
	doixungcheochinh(a,m,n);
	printf("\nGia tri trung binh cong duong :%.2f",trungbinhcong(a,m,n));
	return 0;
}

