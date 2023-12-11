//bai 4A10
#include <stdio.h>
#include <math.h>
int nhapmang(int a[],int n){
for (int i=1;i<=n;i++){
	scanf("%d",&a[i]);
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
		printf("Phan tu tong chan bang phan tu tong le");
		}
		else {
			printf("Tong chan khong bang tong le ");
			}
			}
		int main (){
			int n;
			scanf("%d",&n);
			int a[n];
			nhapmang(a,n);
			kiemtrachanle(a,n);
			return 0;
			}
			

