#include <stdio.h>
#include <math.h>
int main(){
    int n;
    scanf("%d",&n);
    int dem =0;
    int a[9] = {500000,200000,100000,50000,20000,10000,5000,2000,1000};
    for (int i=0;i<9;i++) {
        if (n>=a[i]) {
            int tam = n/a[i];
            n-=tam*a[i];
            dem+=temp;
        }
    }
    if (n!=0) {
        printf("-1");
        
    } 
	else {
        printf("%d",dem);
    }
    return 0;
}