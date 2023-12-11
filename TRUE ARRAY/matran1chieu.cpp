#include <stdio.h>
#include <math.h>
#define MAX 100
void nhap(float a[][MAX],int dong,int cot){
  for (int i=0;i<dong*cot;i++){
      printf("\nNhap a[%d][%d]:",i/cot,i%cot);
            scanf("%f",&a[i/cot][i%cot]);//truy cập vào phần tử của ma trận a i/cot=hang,i%cot=cot
        }
    }
void xuat(float a[][MAX],int dong,int cot){
   for (int i=0;i<dong*cot;i++){
            printf("%.2f ",a[i/cot][i%cot]);
            if((i+1)%cot==0){
                printf("\n");
            }
        }
    }
int main (){
    int m,n;
    printf("\nNhap dong,cot :");
    scanf("%d%d",&m,&n);
    float a[MAX][MAX];
    nhap(a,m,n);
    xuat (a,m,n);
    return 0;
}