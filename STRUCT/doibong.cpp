#include <stdio.h>
#include <math.h>
struct cauthu {
	char ten[30];
	int ban;
	int phut;
	float tienthuong;
};
void nhap (cauthu ct[],int n){
	for (int  i=1;i<=n;i++){
		printf("\nNhap cau thu thu %d :\n",i);
		printf("\nNhap ten :");
		fflush (stdin);
		fgets(ct[i].ten,sizeof(ct[i].ten),stdin);
		printf("\nnhap so ban thang :");
		scanf("%d",&ct[i].ban);
		printf("\nNhap so phut thi dau:");
		scanf("%d",&ct[i].phut);
	}
}
void in (cauthu ct[],int n){
	printf("\n\t\t\tTHONG TIN CAU THU :\n");
	for (int  i=1;i<=n;i++){
	printf("\nCau thu thu %d:\n",i);
	printf("\nTen cua thu :%s",ct[i].ten);
	printf("\nSo ban thang:%d",ct[i].ban);
	printf("\nSo phut thi dau:%d",ct[i].phut);
}
}
void tienthuong(cauthu ct[],int n){
	for (int i=1;i<=n;i++){
		if(ct[i].ban>=3 && ct[i].phut >=500){
			ct[i].tienthuong=50;
		}
		 else if(ct[i].ban>=3 || ct[i].phut >=500){
		   ct[i].tienthuong=20;
		}
	}
	printf("\nTien thuong cua tung cau thu :");
	for (int i=1;i<=n;i++){
		printf("\nTien thuong cua cau thu %d la :%.0f trieu dong.",i,ct[i].tienthuong);
	}
    printf("\nCac cau thu co tien thuong cao nhat doi :\n");
	for (int i=1;i<=n;i++){
		if(ct[i].tienthuong==50){
			printf("\n%s",ct[i].ten);
		}
	}
}

int  main (){
	int n;
	printf("\nSo luong cau thu :");
	scanf("%d",&n);
	cauthu ct[100];
	nhap(ct,n);
	in(ct,n);
	tienthuong(ct,n);
}