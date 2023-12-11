//Bài 1-7 Cho tệp văn bản (tên tệp nhập từ bàn phím) chứa các phần tử của một ma trận 
//nguyên cấp m*n. Tệp có cấu trúc như sau: Dòng đầu chứa các số nguyên m và n là số hàng 
//và số cột của ma trận (giữa hai số m và n có ít nhất một dấu cách). Dòng thứ i+1 (i= 1, 2,... 
//m) chứa các phần tử của hàng thứ i cua ma trận (giữa các phần tử có ít nhất một dấu cách). 
//Hãy viết chương trình (có xây dựng các hàm) để thực hiện:
//1. Đọc ma trận từ tệp. 
//2. Tính tổng các phần tử chằn của ma trận. 
//3. Tim phần tử chằn nhỏ nhất của ma trận và cho biết chỉ số hàng và chỉ số cột của phần 
//từ đó.

#include<bits/stdc++.h>
void  DocFile(int ***a,int &m,int &n,char  *tentep){
	FILE *f;
	f=fopen(tentep,"r");
	// đọc file
	if(f==NULL){
		printf("\nKhong the  mo duoc file.");
		exit(0);
	}
	fscanf(f,"%d%d",&m,&n);
	 *a=(int **)malloc (m*sizeof(int *));
	for(int i=0;i<m;i++){
		(*a)[i]=(int *) malloc  (n*sizeof(int));
	}
	for (int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			fscanf(f,"%d",&((*a)[i][j]));
		}
	}
	printf("\nMa tran duoc doc tu tep la:\n");
	for(int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			printf("%d ",(*a)[i][j]);
		}
		printf("\n");
	}
	fclose(f);	
}
void TongChan(int **a,int m,int n){
	int tong =0;
	for (int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(a[i][j]%2==0){
				tong +=a[i][j];
			}
		}
	}
	printf("\nTong cua ma tran la :%d",tong);
}
void ChanMin(int **a,int m,int n){
	int min=INT_MAX,h=0,c=0;
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			if(min>a[i][j]){
				min=a[i][j];
				h=i,c=j;
			}
		}
	}
	printf("\nGia tri phan tu chan nho nhat la :a[%d][%d]:%d",h,c,min);
}
int  main (){
	int m,n;
	int **a;
	char tentep[50]="Bai1-7.txt";
	DocFile(&a,m,n,tentep);
	TongChan(a,m,n);
	ChanMin(a,m,n);
	return  0;
}