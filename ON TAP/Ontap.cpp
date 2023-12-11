#include <stdio.h>
#include <math.h>
int nguyento(int n){
	if (n<2){
		return 0;
	}
	else {
		for (int i=2;i<=sqrt(n);i++){
		 if(n%i==0)
		 return 0;	
		}
		return 1;
	}
}
int main (){
	// nhap so luong test case 
  int t;
  scanf("%d\n",&t);
  while (t--){
  	int n;
  	scanf("%d",&n);
  	if(nguyento(n)==1)
  		printf("YES\n");
	  else
	  	printf("NO\n");
  }
  return 0;
}