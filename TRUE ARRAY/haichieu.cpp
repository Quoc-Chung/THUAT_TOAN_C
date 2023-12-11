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
	int demsoluongchuso(int n){
		int dem=0;
		while(n>0){
			n/=10;
			dem++;
		}
		return dem;
	}
	
int main (){
	int n;
    printf("Nhap ma tran cap:");
    scanf("%d",&n);
    int a[100][100];
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
		  printf("Nhap phan tu a[%d][%d]",i,j);
		  scanf("%d",&a[i][j]);
		  }
		  }
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			printf("%d ",a[i][j]);
			}
			printf("\n");	
     	}
     	// tong cheo phu
     	int phu=0;
for (int i=0;i<n;i++){
	for (int j=0;j<n;j++){
		if(j==n-1-i || i==n-1-j){
		phu+=a[i][j];
		}
		}
}
printf("\nTong duong cheo phu la :%d",phu);
// tong cheo chinh 
int tong=0;
for (int i=0;i<n;i++){
	for (int j=0;j<n;j++){
		if(i==j){
			tong+=a[i][j];
			}
			}
			}
	printf("\nTong duong cheo chinh la:%d",tong);
	printf("\n Cac chu so nguyen to la :\n");
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			if(nguyento(a[i][j])==1){
				printf("%d",a[i][j]);
				}
				}
				}
		int dem=0;
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			dem += demsoluongchuso(a[i][j]);
		}
	}
	printf("\nSo luong chu so ma tran la :%d",dem);
}
