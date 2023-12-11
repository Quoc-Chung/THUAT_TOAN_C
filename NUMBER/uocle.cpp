
#include <stdio.h>
#include <math.h>
int main(){
	int t;
	scanf("%d",&t);
	while (t--){
	int n;
	scanf("%d",&n);
	for (int i=1;i<1000;i++){
		if(n%i==0 && i%2==1){
	 printf("YES");
	 break;
		}
	}
}
}
