//Cho tệp văn bản chunhat.txt chứa thông tin về n hình chữ nhật. Tệp có cấu trúc
//như sau: Dòng đầu chứa số nguyên n là số hình chữ nhật, từ dòng thứ 2 trở đi mỗi dòng
//chứa 2 số thực lưu trữ kích thước (cạnh dài và cạnh rộng) của một hình chữ nhật (giữa
//hai số thực có ít nhất một dấu cách). Hãy xây dựng các hàm để thực hiện:
//1. Đọc dữ liệu của n hình chữ nhật từ tệp đã cho
//2. Tính diện tích trung bình của n hình chữ nhật.
//3. Tìm một hình có diện tích lớn nhất.
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
struct  HinhCN{
	float dai;
	float rong;
};
void DocFile (HinhCN **h,int &n,char *tentep){
	FILE *f=fopen(tentep,"r");
	if(f==NULL){
		printf("\nKhong the mo duoc file");
		exit(0);
	}
	fscanf(f,"%d",&n);
	(*h)=(HinhCN *) malloc(n*sizeof(HinhCN));
	for(int i=0;i<n;i++){
		fscanf(f,"%f%f", &(*h)[i].dai,&(*h)[i].rong);
	}
}
void TinhDienTich (HinhCN *h,int n){
	float Tong=0;
	for(int i=0;i<n;i++){
		Tong +=h[i].dai *h[i].rong;
	}
	printf("\nDien tich trung binh  cua hinh chu nhat la  :%.2f",Tong/n);
}
void HinhChuNhatMax(HinhCN *h ,int n){
	float max=INT_MIN;
   float Maxdai=0,Maxrong=0;
   for(int i=0;i<n;i++){
   	if(max < h[i].dai*h[i].rong){
   		max =h[i].dai*h[i].rong;
   		Maxdai=h[i].dai;
   		Maxrong=h[i].rong;
	   }
   }
   printf("\nHinh chu nhat co  dien  tich max co kich thuoc  :%.2f %.2f",Maxdai,Maxrong);
}
int  main (){
	int n;
	HinhCN *h;
	char tentep[50]="hinhchunhat.txt";
	DocFile(&h,n,tentep);
	TinhDienTich (h,n);
	HinhChuNhatMax(h,n);
	return 0;
}

