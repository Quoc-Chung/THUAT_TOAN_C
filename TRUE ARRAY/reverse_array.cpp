#include <stdio.h>
#include <math.h>
int main (){
    int n;
    printf("\nNhap cap:");
    scanf("%d",&n);
    // ma tran cap n
    int a[n][n];  
    // tao bien lu gia tri 
    int luu=n*n;
    int cot_dau=0,cot_cuoi=n-1,hang_dau=0,hang_cuoi=n-1;// dinh dang cac hang  
    while (hang_dau<=hang_cuoi && cot_dau<=cot_cuoi){
        // dau tien lam hang dautruoc 
        for (int i=cot_dau;i<=cot_cuoi;i++){
            a[hang_dau][i]=luu;
            luu--;
        }
        hang_dau++;
         // tiep theo ta lam cot cuoi 
         for (int  i=hang_dau;i<=hang_cuoi;i++){
            a[i][cot_cuoi]=luu;
            luu--;
         }
         cot_cuoi--;
         /// làm hang cuoi 
    // ma tran cu chay nguoc thi ta phai kiem tra dieu kien
         if(cot_dau<=cot_cuoi){
            for (int  i=cot_cuoi ;i>=cot_dau;i--){
                a[hang_cuoi][i]=luu;
                luu--;
            }
            hang_cuoi--;
         }
        // lam cot dau
          if(hang_dau<=hang_cuoi){
            for (int i=hang_cuoi ;i>=hang_dau;i--){
                a[i][cot_dau]=luu;
                luu--;
            }
             cot_dau++;
          }
        }
    printf("\nMa tran xoay nguoc la :\n");
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}