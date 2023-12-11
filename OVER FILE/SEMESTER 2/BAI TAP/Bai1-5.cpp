//Cho tệp văn bản (tên tệp nhập từ bản phím) chứa các phân tử của một ma trận 
//thực cấp mxn. Tệp có cấu trúc như sau: dòng đầu chứa các số nguyên m và n (giữa hai số 
//m và n có ít nhất một dấu cách). Dòng thứ i+1 (i=1,2... m) chứa các phần tử của hàng thứ 
//i của ma trận (giữa các phần tự có ít nhất một dấu cách). Xây dựng các hàm để thực hiện: 
//1. Đọc ma trận từ tệp, có cấp phát động bộ nhớ, in ma trận ra màn hình. 
//2. Tinh tích của từng hàng của ma trận và cho biết hàng nào có tổng nhỏ nhất. 
//3. Đếm số phân tử dương của ma trận
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
/*--Cần phải cấp phát bộ nhớ  động trước  khi--*/
  void Doc_ma_Tran_Tu_Tep(int **&a,int &m,int &n){
	char  duong_dan[100]="C:\\Users\\Admin\\Documents\\LAP TRINH\\DEV C++\\THUATTOANC\\WORK FILE\\LUU TRU\\Bai Tap\\Bai1-5.txt";

	FILE *f;
	f=fopen(duong_dan,"r");
    if(f==NULL){
    	printf("\nKhong  mo duoc file.");
    	exit(1);
	}
	fscanf(f,"%d%d",&m,&n);
    a= (int **) malloc(m*sizeof(int *));
    for (int i = 0; i < m; i++)
    {
       // Cấp phát cho từng con trỏ cấp 1
        a[i] = (int *)malloc(n * sizeof(int));
    }
   
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			fscanf(f,"%d",&a[i][j]);
		}
	}
	fclose(f);
}
void In_Tep_Ra_Man_Hinh(int **a,int m,int n){
	printf("\nMa tran vua doc  tu file la :\n");
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
}
void Tich_Tung_Hang(int **a,int m,int n){
	printf("\nTich tung hang cua  ma tran la :");
	for(int  i=0;i<m;i++){
		int tich=1;
		for(int j=0;j<n;j++){
			tich*=a[i][j];
		}
		printf("\nHang %d: %d",i,tich);
	}
}
int main(){
	int m,n;
    int **a;
    Doc_ma_Tran_Tu_Tep(a,m,n);
    In_Tep_Ra_Man_Hinh(a,m,n);
    Tich_Tung_Hang(a,m,n);
    return 0;
}