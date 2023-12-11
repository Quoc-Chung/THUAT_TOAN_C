// cac bai tap co ban voi ma tran
#include <stdio.h>
#include <math.h>
int nguyento(int n){
    if(n<2){
        return 0;
    }
    else {
        for (int i=2;i<=sqrt(n);i++){
            if(n%i==0)
            return 0;
        }
    }
    return 1;
}
int nhapmang(int a[][100],int m,int n){
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			printf("Nhap mang a[%d][%d]: ",i,j);
			scanf("%d",&a[i][j]);
			}
			}
			}
int inmang (int a[][100],int m,int n){
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			printf("%d ",a[i][j]);
			}
			printf("\n");
			}
			}
int tong(int a[][100],int m,int n){
	int tong =0;
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			tong+=a[i][j];
			}
			}
			return tong;
			}
int tich(int a[][100],int m,int n){
	int tich=1;
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			tich=tich*a[i][j];
			}
			}
			return tich;
			}
				
int solonnhat (int a[][100],int m,int n){
	int x=0,y=0;
	int max=a[0][0];
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			if(max<a[i][j]){
				max=a[i][j];
				x=i;
				y=j;
				}
				}
				}
	printf("Phan tu max co vi tri hang %d cot %d co gia tri %d",x,y,max);
		}
int sonhonhat(int a[][100],int m,int n){
	int min =a[0][0];
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			if (min > a[i][j]){
				min =a[i][j];
				}
				}
				}
				return min ;
		}
	
int main (){
	int m,n;
	int a[100][100];
	scanf("%d%d",&m,&n);
	nhapmang (a,m,n);
	printf("\nMa tran la :\n");
	inmang (a,m,n);
	printf("Tong ma tran:%d và tich ma tran:%d",tong(a,m,n),tich(a,m,n));
	solonnhat (a,m,n);
	printf("\n So nho nhat mang :%d",sonhonhat (a,m,n));
	printf("\nCac so nguyen to trong ma tran la :\n");
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
		if(nguyento(a[i][j])){
		printf("%d ",a[i][j]);
		}		
	}
	}
	return 0;
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
