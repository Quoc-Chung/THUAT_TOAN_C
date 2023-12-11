#include <stdio.h>
#include <math.h>     
int main(){
    int s,m;
    int so1,so2;
    int flag=0;
    scanf("%d %d",&s,&m);
    for (int i=(s-m)/2;i<=(s+m)/2;i++){
    	so2==s-i;
       if(i-so2==m){
       	printf("%d %d",so1,so2);
       	flag++;
       	break;
	   }
    }
	if(flag==0){
		printf("-1");
	}
    return 0;
}