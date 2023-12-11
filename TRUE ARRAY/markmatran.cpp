#include <stdio.h>
#include <math.h>
#include <stdlib.h>
//#define MAX_VALUE 1000 // định  nghĩa một giá trị max =1000 chinh la so luong gia tri mang
int count[100006] = {0};
void input (int *a,int m,int n ){
    for (int  i=0;i<m;i++){
        for (int j=0;j<n;j++){
            printf("a[%d][%d]:",i,j);
            scanf("%d",(a+i)+j);
        }
    }
}
void output(int *a,int m,int n){
    printf("\nMa tran la :\n");
    for(int i=0;i<m;i++){
        for (int j=0;j<n;j++){
          printf("%d ",*((a+i)+j));
        }
        printf("\n");
    }
}
void mark(int *a,int m,int n){
   for(int i = 0;i < m;i++) {
        for (int j = 0;j<n;j++){
// i*n+j là công thức tính vị trí của phần tử a[i][j] ==> mảng 1 chiều a[i*n+j]
        count[a[i*n+j]]++;
 // tang gia tri trong  mang tai vi tri là gia tri mang dẻ cac gí tri dù
    // mang gia tri nhu nhau nhung no cung chi duoc xuat hien mot lan .
        }
    }
    printf("Cac phan tu xuat hien trong mang la:\n");
    for(int i =0;i<100006;i++){
    	for (int j=0;j<100006;j++){
        if (count[a[i*n+j]]==1){// neu mang 
            printf("%d ",a[i*n+j]);// i chinh la gia tri a[i] ma mang danh dau 
        }
    }
}
}
//.\mark đây là cách để chạy lại chương trình 
int main(){
    int m,n;
    int a[100][100]; 
    printf("Nhap m va n:");
    scanf("%d%d",&m,&n);
    input(&a[0][0],m,n);
    output(&a[0][0],m,n);
    mark(&a[0][0],m,n);
    return 0;
}