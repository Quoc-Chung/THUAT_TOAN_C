#include <stdio.h>
#include <math.h>
int demsochan(int n){
	int demchan=0;
	while (n>0){
		int s=n%10;
		if(s%2==0){
			demchan++;
			}
			n=n/10;
			}
			return demchan ;
			}
int demsole(int n){
	int demle=0;
	while (n>0){
		int s=n%10;
		if(s%2==1){
			demle++;
			}
			n=n/10;
			}
			return demle;
			}
			int main (){
				int n;
				scanf("%d",&n);
				int a=demsochan(n);
				int b=demsole(n);
				if(a==0 && b== 0){
					printf("0");
					}
					else{
				printf("%d %d",a,b);
				}
				}
			
