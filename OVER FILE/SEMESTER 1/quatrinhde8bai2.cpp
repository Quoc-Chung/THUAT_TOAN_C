
//- Thống kê số sinh viên dự thi của 3 trường
#include <stdio.h>
#include <math.h>
#include <string.h>
struct thisinh{
	char ten[30];
	char que[30];
	char truong[2];
	int soBD;
	float diem;
};
//Xây dựng một cấu trúc ứng với phiếu điểm của thí sinh thi học sinh giỏi gồm các 
//thành phần:Họ tên,Quê quán,Trường(giả sử có 3 trường dự thi là A,B C), Số báo danh,Điểm thi
void nhapthisinh(struct thisinh ts[],int n){
	for (int i=1;i<=n;i++){
		printf("Nhap thong tin thi sinh thu %d",i);
		printf("\nNhap ho va ten :");
	    fflush(stdin);
		fgets(ts[i].ten,sizeof(ts[i].ten),stdin);
		printf("\nNhap que quan:");
		fflush(stdin);
		fgets(ts[i].que,sizeof(ts[i].que),stdin);
		printf("\nNhap truong :");
		fflush(stdin);
		fgets(ts[i].truong,sizeof(ts[i].truong),stdin);
		printf("\nNhap so bao danh :");
		scanf("%d",&ts[i].soBD);
		printf("\nNhap diem thi sinh :");
		scanf("%f",&ts[i].diem);
	}
}
void inthisinh(struct thisinh ts[],int n){
	printf("\nThong tin cua sinh vien la:\n");
	for(int i=1;i<=n;i++){
	   printf("\nHo va ten :%s",ts[i].ten);
	   printf("\nQue quan:%s",ts[i].que);
	   printf("\nTruong :%s",ts[i].truong);
	   printf("\nSo bao danh:%d",ts[i].soBD);
	   printf("\nDiem thi sinh :%.2f",ts[i].diem);	
	}
}
//- Tìm kiếm và in ra các thí sinh có điểm thi >= 15
void search (struct thisinh ts[],int n){
	int vitri=0;
	printf("\nCac thi sinh co diem tren 15 la :\n");
	for (int i=1;i<=n;i++){
		vitri=0;
		if(ts[i].diem>=15){
			vitri=i;
			printf("%s",ts[vitri].ten);
		}
	}
}
//- Sắp xếp lại các phần tử của mảng cấu trúc theo thứ tự giảm dần của điểm, sau đó in 
//danh sách thí sinh.
void swap(struct thisinh ts[],int n){
	struct thisinh tam;
	for (int i=1;i<=n;i++){
		for (int j=i+1;j<=n;j++){
			if(ts[i].diem<ts[j].diem){
				tam=ts[i];
				ts[i]=ts[j];
				ts[j]=tam;
			}
		}
	}
	printf("\nDanh sach thi sinh la:\n");
	for (int i=1;i<=n;i++){
		printf("%s\n",ts[i].ten);
	}
}
void thongke(struct thisinh ts[],int n){
	char a[2]="A",b[2]="B",c[2]="C";
	int dem1=0,dem2=0, dem3=0;
	for (int i=1;i<=n;i++){
		if(strcmp(ts[i].truong,a)==0){
			dem1++;
		}
			if(strcmp(ts[i].truong,b)==0){
			dem2++;
		}
			if(strcmp(ts[i].truong,c)==0){
			dem3++;
		}
	}
	printf("\nSo sinh vien truong A la :%d",dem1);
	printf("\nSo sinh vien truong B la :%d",dem2);
	printf("\nSo sinh vien truong C la :%d",dem3);
}
int main (){
	int n;
	printf("Nhap n:");
	scanf("%d",&n);
	struct thisinh ts[100];
	nhapthisinh(ts,n);
	//inthisinh(ts,n);
	//search (ts,n);
	//wap(ts,n);
	thongke(ts,n);
}

