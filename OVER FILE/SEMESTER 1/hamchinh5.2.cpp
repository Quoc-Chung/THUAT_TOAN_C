#include <stdio.h>
#include <math.h>
int main (){
		int m,n;
	scanf("%d%d",&m,&n);
	int a[100][100];
		for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			printf("Nhap mang a[%d][%d]:",i,j);
		 scanf("%d",&a[i][j]);	
		}
	}
	int min=a[0][0];// ta coi min la gia tri dau trong ma tran de so sanh
// ban chat tim min cot la ta duyt tung cot m?t ,v?i m?i c?t ta lai duyt tu hang 1 d?n hàng cu?i

	int j=0;
	while (j<n){
		min=a[0][j];
		for (int i=0;i<m;i++){
			if(min>a[i][j]){
				min=a[i][j];
			}
		}
		printf("%d\n",min);
		j++;
	}
}