// dem so luong chinh phuong trong doan
#include <stdio.h>
#include <math.h>
int kiemtra(int n){
	int flag=0;
	if(n==1){
		flag=1;
	}
	else{
	for (int i=2;i<=sqrt(n);i++){
		if(i*i==n){
			flag=1;
		}
	}
	if(flag==1){
		return 1;
	}
	else if(flag==0){
		return 0;
	}
}
}
int main (){
	int t;
	scanf("%d",&t);
	while (t--){
		int m,n;
		scanf("%d%d",&m,&n);
		int dem=0;
		for (int i=m;i<=n;i++){
			if(kiemtra(i)==1){
				dem++;
			}
		}
		printf("%d",dem);
		
}
}
	
