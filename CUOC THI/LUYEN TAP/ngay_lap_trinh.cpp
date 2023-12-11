#include <stdio.h>
#include <math.h>
int check(int year) 
 {
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        return 1;
    } else {
        return 0;
    }
}
int main (){
	int n;
	scanf("%d",&n);
	if(n<2009){
		printf("-1");
	}
	else if(n>=2009) {
		if(check(n)==0){
		printf("\n12.09.%d - Happy Programmer's Day!",n);
	}
	if(check(n)==1){
		printf("\n13.09.%d - Happy Programmer's Day!",n);
	}
	}  
}