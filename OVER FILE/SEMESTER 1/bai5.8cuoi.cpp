#include <stdio.h>
#include <math.h>
void nhapmang (int a[100][100],int n){
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			scanf("%d",&a[i][j]);
		}
	}
}
void inmang(int a[100][100],int n){
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
}
 void tinhbaicuoi(int a[100][100],int u,int v,int n){
	int tong=0;
	for (int i=u;i<=n;i++){
		for (int j=v;j<=;j++){
			tong +=a[i++][j++];
		}
	}
	printf("Tong can tinh la :%d",tong);
}
int main(){
	int n;
	printf("Ma tran cap: ");
	scanf("%d",&n);
	int a[100][100];
	nhapmang(a,n);
	printf("Ma tran la :\n");
	inmang(a,n);
	int u,v;
	scanf("%d%d",&u,&v);

	tinhbaicuoi(a,u,v);
}