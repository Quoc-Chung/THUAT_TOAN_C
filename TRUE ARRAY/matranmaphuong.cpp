#include <stdio.h>
#include <math.h>
void nhapmang(int a[100][100],int n){
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			scanf("%d",&a[i][j]);
		}
	}
}
void inmang(int a[100][100],int n){
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			printf("%d",a[i][j]);
		}
	}
}
int tongcheochinh(int a[100][100],int n){
	int tong=0;
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			if(i==j){
				tong+=a[i][j];
			}
		}
	}
	return tong;
}
int cheophu(int a[100][100],int n){
	int tong=0;
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			if(i==n+1-j || j==n+1-i){
				tong+=a[i][j];
			}
		}
	}
	return tong;
}
int main (){
	int n;
	scanf("%d",&n);
	int a[100][100];
	nhapmang(a,n);
	printf("Ma tran la :\n");
	inmang(a,n);
	int cheoc=tongcheochinh(a,n);
	int cheop=cheophu(a,n);
	printf("\n%d",cheoc);
	printf("\n%d",cheop);
	
}