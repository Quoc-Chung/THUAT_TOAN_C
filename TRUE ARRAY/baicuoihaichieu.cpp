#include <stdio.h>
#include <math.h>
void nhapmang (int a[100][100],int n){
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			scanf("%d",&a[i][j]);
		}
	}
}
void inmang (int a[100][100],int n){
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
}
void tongduongchepphu(int a[100][100],int n){
	int tong=0;
	for(int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			if(j==n-1-i || i==n-1-j){
				tong+=a[i][j];
			}
		}
	
	}
	printf("\nTong duong cheo phu la:%d",tong);
}
void maxmatran(int a[100][100],int n){
	int max=0;
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			if(max<=a[i][j]){
				max=a[i][j];
			}
		}
	}
	printf("\nGia tri cua max la :%d",max);
}
void tichtungcot (int a[100][100],int n){
	int tich;
	for (int j=0;j<n;j++){
		 tich =1;
		for(int i=0;i<n;i++){
			tich *=a[i][j];
		}
		printf("\n%d\n",tich);
	
	}
	
}// tim vi tri cot co tong lon nhat 
 int tongdongdau(int a[100][100],int i,int n){
 	int tong =0;
 	for (int j=0;j<n;j++){
 		tong +=a[i][j];
	 }
	 return tong ;
 }
int hangcotonglonnhat(int a[100][100],int n){
	int dong=0,sum;
    int max=tongdongdau(a,0,n);
// dat max la tong dong dau tien 
	for (int i=1;i<=n;i++){
		sum=0;
		for (int j=0;j<n;j++){
			sum +=a[i][j];
		}
		if(max<=sum){
			max=sum;
			dong=i;
		}
	}
	return dong;
}
int main (){
	int n;
	printf("Ma tran cap :");
	scanf("%d",&n);
	int a[100][100];
	nhapmang(a,n);
	printf("Ma tran la :\n");
	inmang(a,n);
	tongduongchepphu(a,n);
	maxmatran(a,n);
	printf("\nTich tung cot cua ma tran  la :\n");
	tichtungcot(a,n);
	printf("\nHang co tong lon nhat la :%d",hangcotonglonnhat(a,n));
	
}