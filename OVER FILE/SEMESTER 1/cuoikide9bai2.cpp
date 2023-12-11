#include <stdio.h>
#include <math.h>
void nhapmang(float  a[100][100],int &m,int &n){
	do{
		printf("Nhap kich thuoc :");
		scanf("%d%d",&m,&n);
		if(m<0 || n<0){
			printf("\nVui lòng nhập lại :");
		}
	}while (m<0 || n<0);
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			printf("Nhap gia tri a[%d][%d]:",i,j);
			scanf("%f",&a[i][j]);
		}
	}
}
void inmang(float a[100][100],int m,int n){
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			printf("%.1f ",a[i][j]);
		}
		printf("\n");
	}
}
void timmaxtunghang(float a[100][100],int m,int n){
	printf("\nMax cua tung hang la :\n");
	float max=a[0][0];// đặt max số đầu tiên của ma trận 
	int i=0;// đặt hàng dầu tiên ta duyệt có chỉ số 0 để duyệt vòng while
	while (i<m){
		max=a[i][0];// đặt min từng hàng đều ở cột đầu tiên của từng hàng 
		for (int j=0;j<n;j++){
			if(max<a[i][j]){
				max=a[i][j];
			}
		}
		printf("\n%.2f\n",max);
		i++;
	}
}
void timmintungcot (float a[100][100],int m,int n){
	printf("\nMin cua tung hang la:\n");
	float min=a[0][0];//dat min la phan tu đầu tiên của ma trận 
	int j=0; // ta sẽ cài chay tu cot dau tien de chay vòng while 
	while (j<n){// điều kiện để vòng while dừng 
		min=a[0][j];//ta sẽ đat min la phan tu dau hang de tien hanh so sanh itm min 
		for (int i=0;i<m;i++){
			if(min>a[i][j]){
				min=a[i][j];
			}
		}
		// het vong for thi ta se in ra min cua cot vua tim duoc va tiến hành nhảy cột bằng cách tăng j++
		printf("%.1f\n",min);
		j++;
	}
}
// tính và in ra màn hình b[j] với b[j] là giá trị lớn nhất của cột thứ j
void maxcotnhap(float a[100][100],int m,int n,int &cot){
	do{
		printf("\nNhap cot :");
		scanf("%d",&cot);
		if(cot <0 || cot >n){
			printf("\nVui long nhap lai cot.");
		}
	} while (cot <0 || cot >n);
	cot+=1;
	float max=a[0][cot];
	for (int i=0;i<m;i++){
		if(max<a[i][cot]){
			max=a[i][cot];
		}
	}
	printf("\n Gia tri max cua cot vua nhap la :%.2f",max);
}	
int main (){
	int m,n;
	int cot;
	float a[100][100];
	nhapmang(a,m,n);
	inmang(a,m,n);
//	timmaxtunghang(a,m,n);
//	timmintungcot(a,m,n);
    maxcotnhap(a,m,n,cot);
	return 0;	
	}