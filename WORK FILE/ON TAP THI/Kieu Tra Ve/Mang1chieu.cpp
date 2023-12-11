#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int* ReadFile_Array(int  **a,int  &n,char  *tentep){
    FILE  *f=fopen(tentep,"r");
    if(f==NULL){
        printf("\nKhong the  doc duoc file  ");
        exit(0);
    }
    fscanf(f,"%d",&n);
    (*a)=(int *)malloc  (n*sizeof(int));
    for (int i=0;i<n;i++){
        fscanf(f,"%d",&(*a)[i]);
    }
  return  *a;
}
int  main (){
    int  n;
    char tentep[50]="Mang1chieu.txt";
    int  *a;
    int  *b=ReadFile_Array(&a,n,tentep);
    printf("\nMang duoc doc tu tep la :\n");
    for  (int  i=0;i<n;i++){
        printf(" %d",b[i]);
    }
    return 0;
}