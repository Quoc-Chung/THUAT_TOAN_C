
#include <stdio.h>
#include <math.h>
int nhapmang(int a[],int n){
for (int i=1;i<=n;i++){
	scanf("%d",&a[i]);
	}
}
int inmang (int a[],int n){
	for (int i=1;i<=n;i++){
		printf("%d",a[i]);
		}
		}
int kiemtrasapxep(int a[],int n){
	int flag=0;
	for (int i=1;i<n;i++){
		if(a[i]<a[i+1]){// tuc la a dau < a sau
			flag=1;
			}
			else{
			flag=2;
			break;
			} 
		}
		if(flag==1){
			printf("\nMang sap xep tang dan !");
			}
		else {
			printf("\nMang khong sap xep tang dan ");
			}
			}
	int kiemtrachanle(int a[],int n){
	int tongchan=0,tongle=0;
	for (int i=1;i<=n;i++){
		if(a[i]%2==0){
			tongchan+=a[i];
			}
		else{
			tongle+=a[i];
		}
		}
	if(tongchan==tongle){
		printf("\nPhan tu tong chan bang phan tu tong le");
		}
		else {
			printf("\nTong chan khong bang tong le ");
			}
			}
int tonggiatri(int a[],int n){
	int tongtren=a[1]*a[n];
	int day=0;
	 for (int i=1;i<=n;i++){
	 	tongtren+=a[i]*a[i+1];
	 	day+=i;
	 	}
	 	return tongtren/day;
	 	}
		int main (){
			int n;
			scanf("%d",&n);
			int a[n];
			nhapmang(a,n);
		 printf("Mang in ra la :\n");
		   inmang (a,n);
		   kiemtrasapxep(a,n);
		   kiemtrachanle (a,n);
		   printf("\nTong gia tri:%d",tonggiatri(a,n));
			return 0;
			}
			

