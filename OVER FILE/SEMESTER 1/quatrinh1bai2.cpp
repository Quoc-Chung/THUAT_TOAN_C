//Câu 2: Nhập, xuất vào một ma trận nguyên cấp mxn, thực hiện các yêu cầu sau:
// Tính tổng các phần tử thuộc cột lẻ của ma trận.
// Tính trung bình cộng các phần tử chẵn lớn hơn 10 trong ma trận.
// Tìm giá trị lớn nhất của ma trận.
#include <stdio.h>
#include <math.h>

void nhapmang(int a[100][100],int m,int n){
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			printf("Nhap phan thu a[%d][%d]:",i,j);
			scanf("%d",&a[i][j]);
		}
	}
}
void inmang(int a[100][100],int m,int n){
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
}
// Tính tổng các phần tử thuộc cột lẻ của ma trận.
// tuc la duyet tung cot -----  kiem tra cot le  -----  duyet tu hang dau den hang cuoi 
void tongcotle (int a[100][100],int m,int n){
	int tongle;
	for (int j=0;j<n;j+=2){
		tongle=0;
		for (int i=0;i<m;i++){
			tongle+=a[i][j];
		}
		printf("\n%d",tongle );	
	}
}
//  Tính trung bình cộng các phần tử chẵn lớn hơn 10 trong ma trận.
float trungbinhcong (int a[100][100],int m,int n){
	int dem=0;
	int tong=0;
	int flag=0;
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			if(a[i][j]%2==0  && a[i][j]>10){
				flag++;
				tong +=a[i][j];
				dem++;
			}
    }
			
			
		}
		if(flag==0){
			printf("\nKhong co gia tri nao lon hon 10.");
		}
		else {
			
			
		return 1.0*tong/dem;
	}	
}
void tongtungcot(int a[100][100],int m,int n){
	   int tong;
	for (int j=0;j<n;j++){
		tong=0;
	for (int i=0;i<m;i++){
		 tong+=a[i][j];	
		}
		printf("\n%d",tong);
	}
	
}
// gia tri lon nhat cua ma tran thi qua la de roi 
int main (){
	int m,n;
	printf("Nhap kich thuoc m va n:");
	scanf("%d%d",&m,&n);
	int a[100][100];
	nhapmang(a,m,n);
	printf("\nMa tran vua nhap la :\n");
	inmang(a,m,n);
//	printf("\nTong cac cot le la :");
//	tongcotle(a,m,n);
//	printf("\nGia tri trung binh cong la :%.2f",trungbinhcong(a,m,n));
    printf("\nTong tung cot :\n");
    tongtungcot(a,m,n);
	return 0;
}
