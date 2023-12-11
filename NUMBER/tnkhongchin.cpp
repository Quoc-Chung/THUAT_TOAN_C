// kiemtra so thuan nghich va so khong chia het cho 9
#include <stdio.h>
#include <math.h>
int daoso(int n){
	int sodao=0;
	while (n>0){
		sodao=sodao*10+n%10;
		n=n/10;
	}
	return sodao;
}
int kiemtra(int n){
	while (n>0){
		if(n%10==9)
			return 0;
			n=n/10;
	}
	return 1;
}
	int main(){
	    int n;
	    scanf("%d",&n);
	    int dem =0;
	    for (int i=2;i<n;i++){
	    	if(daoso(i) ==i && kiemtra(i)){
	    		printf("%d ",i);
	    		dem ++;
			}
		}
		printf("\n%d\n",dem);
		}
		

