// in sochinh phuong tren doan voi nhieu test case 
#include <stdio.h>
#include <math.h>
int kiemtra(int n){
	int flag=0;
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
int main (){
	int t;
	printf("Nhap gia tri t:");
	scanf("%d",&t);
	while (t--){
		int m,n;
		scanf("%d%d",&m,&n);
	for (int i=m;i<=n;i++){
		if(kiemtra(i)){
			printf("%d ",i);
		}
	}


}
}

	

