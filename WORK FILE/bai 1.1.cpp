#include<math.h>
#include<stdio.h>
#include<stdlib.h>
void Readfile(float**a,float**b,int *n,int *m,char *tentep)
{
FILE *f;
int i;
f=fopen(tentep,"r");
fscanf(f,"%d%d",n,m);
*a=(float*)calloc(*n+1,sizeof(float));
*b=(float*)calloc(*m+1,sizeof(float));
for (i=0;i<=*n;i++) fscanf(f,"%f",*a+i);
for (i=0;i<=*m;i++) fscanf(f,"%f",*b+i);
fclose(f);
}
void Print(float *a, int n, char dt)
{ printf("%c(x)=%.1f",dt,a[0]);
for (int i=0;i<=n;i++) printf(" + %.1fx^%d");
printf("/n");

}
  main(){
  float *a,*b;
  int m,n;
  char tentep[50];
  printf("nhap ten tep du lieu:"); gets(tentep);
  Readfile(&a,&b,&n,&m,tentep);
  Print(a,n,'P');
  Print(b,m,'Q');
 	
 }
//C:\\Users\\Admin\\Documents\\LAP TRINH\\DEV C++\\THUATTOANC\\WORK FILE\\LUU TRU\\Bai Tap\\Bai1-1.txt