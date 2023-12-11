
#include<stdio.h>
#include <math.h>
// dùng de quy
int fibonacci(int n){
    if(n==1||n==0||n==2||n==3) {// cac so dau tien cua day fibonaci
	   return n;
	}
	else {
     return fibonacci(n-2)+fibonacci(n-1);// lúc này doi truyen vao se la n-1 va n-2;
}
}
int main()
{ 
  int n;
   scanf("%d",&n);
   int flag=0;
   for(int i=0;i<=n;i++)
       if(n==fibonacci(i))
       {
            flag=1;            
       }
   if(flag==1) {
   printf("thuoc day fibonacci");
   }
   else{
    printf("Khong thuoc day fibonacci",n);
    }
   return 0;
} 
// day fibonacci la 1 1 2 3 5 8 13
