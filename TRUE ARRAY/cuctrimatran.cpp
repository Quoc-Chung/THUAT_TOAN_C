#include <stdio.h>
#include <math.h>
#include <limits.h>
void nhapmang(int  a[100][100],int m,int n){
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			printf("Nhap gia tri a[%d][%d]:",i,j);
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
void timcuctri(int a[100][100],int m,int n){
	int dem=0;
	int max=INT_MIN;// quy chuẩn tìm max là cho max la một số cực nhỏ 
	int min=INT_MAX;// đật min la một số cực lớn
	printf("\nCac gia tri cuc tri la :\n");
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
		// xet ben tren 	
		if(i-1>=0){	
				max=(max<a[i-1][j])?max:a[i-1][j];
				min=(min>a[i-1][j])?min:a[i-1][j];	
			}
			if(i+1!=m){
				max=(max<a[i+1][j])?max:a[i+1][j];
				min=(min>a[i+1][j])?min:a[i+1][j];
			}
			if(j-1>=0){
				max=(max<a[i][j-1])?max:a[i][j-1];
				min=(min>a[i][j-1])?min:a[i][j-1];
			}
			// xét bên phải 
			if(j+1!=n){
				max=(max<a[i][j+1])?max:a[i][j+1];
				min=(min>a[i][j+1])?min:a[i][j+1];
			}
			// nếu tồn tại môt sô lớn hơn cac so xung quanh hoac nho hon nhung so xung quanh
	        if(a[i][j]> max ||  a[i][j] < min){
	        	printf("%d ",a[i][j]);
	        	dem++;                  
	        	                        
			}	
		}
	}
	printf("\nCac cục tri cua ma tran la  :%d",dem);
}
int main(){
	int m,n;
	printf("Nhap kich thuoc :");
	scanf("%d%d",&m,&n);
	int a[100][100];
	nhapmang(a,m,n);
	inmang (a,m,n);
	timcuctri(a,m,n);
	return 0;
}
           