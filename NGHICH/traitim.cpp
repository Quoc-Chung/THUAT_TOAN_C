#include <stdio.h>
#include <math.h>
int draw (int m,int n){
    int i,j;
    for (int i=1;i<=15;i++){// i l� h�ng 
        for (int j=1;j<=15;j++){//j l� cot
if(!((i==1 && (j==1 || j==2 ||j==3 ||j==6 ||j==7 ||j==8 ||j==9 ||j==10 ||j==13 ||j==14 ||j==15))
 || (i==2 &&(j==1 ||j==2 || j==7 || j==8 ||j==9||j==14||j==15))
 ||(i==3 && (j==1 ||j==15))
 ||(i==4 && (j==1 ||j==15))
 ||(i==9 && (j==1||j==15))
 ||(i==10 && (j==1 || j==15))
 ||(i==11 &&(j==1 ||j==2 ||j==14 ||j==15))
 ||(i==12 && (j==1 ||j==2 ||j==3 ||j==13 ||j==14 ||j==15))
 ||(i==13 && (j==1 ||j==2 ||j==3 ||j==4 || j==12 ||j==13 || j==14 || j==15))
 ||(i==14 &&(j==1 ||j==2 ||j==3 || j==4 ||j==5 ||j== 11 || j==12 ||j==13 ||j==14 ||j==15))
 ||(i==15 &&(j<=7 ||j>=9)))){
                printf(" * ");
            }
            else {
                printf("   ");
            }
        }
        printf("\n");
    }
}
int main(){
    int m=15,n=15;
draw(m,n);
    return 0; 
}
