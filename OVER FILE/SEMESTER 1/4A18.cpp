#include <stdio.h>
#include <math.h>
int nhapmang (int a[],int n){
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		}
		}
int inmang(int a[],int n){
	for (int i=1;i<=n;i++){
		printf("%d ",a[i]);
		}
		}
int trungbinhcong(int a[],int n){
	int dem=0;
	int tong=0;
	for (int i=1;i<=n;i++){
		tong+=a[i];
		dem++;
		}
		return tong/dem;
}
int channhohonx(int a[],int n,int x){
	int flag=0;
	for (int i=1;i<=n;i++){
		if(a[i]%2==0 && a[i]<x){
			printf("%d ",a[i]);
			}
			else{
				flag++;
			}
			}
			if(flag==n){
				printf("day khong co so thoa man");
				}
}
int daykhonggiam(int a[],int n){
	int flag =0;
	for (int i=1;i<=n;i++){
		if(a[i]<a[i+1]){
			flag=1;
			}
		else {
			flag=2;
			break;
			}
		}
		if(flag==1){
			printf("\nDay luôn tang nhé.");
			}
		else {
			printf ("\nDay khong don dieu giam.");
			}
			}
			
int daonguocday(int a[],int n){
	for (int i=n;i>=1;i--){
		printf("%d ",a[i]);
		}
		}
				
int sapxep(int a[],int n){

	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			if(a[i]%2==0 && a[i]<=a[j]){
				int sapxep=a[i];
				a[i]=a[j];
				a[j]=sapxep;
				}
				}
				}
	
		for(int i=1;i<n;i++){
        for (int j=i+1;j<=n;j++){
            if (a[j]%2==0){
                int t = a[i];
                a[i]=a[j];
                a[j]=t;
               break;// for dung khi het so chan
            }
        }
        }
    printf("\nMang sau khi sap xep: ");
    for(int i=1;i<=n;i++)
        printf("%d ",a[i]);
				}
				
int sapxeptangdan(int a[],int n){
	int sapxeptang ;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			if(a[i]<a[j]){
				sapxeptang=a[i];
				a[i]=a[j];
				a[j]=sapxeptang;
				}
				}
				}
				return sapxeptang;
				}
int main (){
int n;
scanf("%d",&n);
int a[n];
printf("Nhap mang :\n");
nhapmang(a,n);
printf("\nIn mang :\n");
inmang (a,n);
int x;
printf("\n NHap x:\n");
scanf("%d",&x);
printf("\nTrung binh cong cua day la :%d",trungbinhcong(a,n));
printf("\nCac phan tu chan nho hon x la :\n ");
	channhohonx(a,n,x);
	daykhonggiam(a,n);
	printf("\nDay dao nguoc la :\n");
	daonguocday(a,n);
	// sapxepday;
	printf("\nDay sap xep tang dan :\n");
	for (int i=1;i<=n;i++){
		sapxeptangdan(a,n);
		printf("%d ",a[i]);
		}
	sapxep(a,n);
	}

	
	


				
				
			














