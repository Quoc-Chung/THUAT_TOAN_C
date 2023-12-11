#include <stdio.h>
#include <math.h>
// dieu kien de mot so nam o duong cheo phu la j==n-1-i || i==n-1-j
// dieu kien nam tren duong cheo chinh la i=j
// dieu kien de la ma tran tam giac duoi la i>j va a[i][j]==0
// nam phia tren duong cheo phu se co cac truong hop sau           (((i==0 && j!=(n-1)) ||(i!=(n-1) && j==0) )  
			                                                       // || ((i==j) && i<(n/2))
			   
		                                                         	//  || ((i!=j)&& i<(n/2) && j<(n/2))
void nhapmang(int a[100][100],int n){
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			printf("Nhap chi so a[%d][%d]:",i,j);
			scanf("%d",&a[i][j]);
		}
	}
}
void inmang (int a[100][100],int n){
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			printf("%d  ",a[i][j]);
		}
		printf("\n");
	}
	
}
 void trencheophu(int a[100][100],int n){
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			if(((i==0 && j!=(n-1)) ||(i!=(n-1) && j==0) )  
			   || ((i==j) && i<(n/2))
			   
			  || ((i!=j)&& i<(n/2) && j<(n/2))
			    ){				
				printf("%d  ",a[i][j]);
			}
		 }
		}	
	}

int main(){
	int n;
	printf("Ma tran cap :");
	scanf("%d",&n);
	int a[100][100];
	nhapmang(a,n);
	printf("Mang ma tran la :\n");
	inmang(a,n);
	printf("Cac phan tu nam tren duong cheo phu la :\n");
	trencheophu(a,n);
}