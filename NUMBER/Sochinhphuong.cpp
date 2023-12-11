//kiemtrasochinhphuong
#include <stdio.h>
#include <math.h>
void kiemtra(int n){
	int flag=0;
	for (int i=2;i<=sqrt(n);i++){
		if(i*i==n){
			flag=1;
		}
		break;
}
		if(flag==1){
			printf("YES");
		}
		else if(flag==0){
			printf("NO");
		}
	}
int main(){
	int t;
	scanf("%d",&t);
	while (t--){
		int n;
		scanf("%d",&n);
		kiemtra(n);
		
	}
}
