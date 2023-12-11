#include <stdio.h>
#include <stdlib.h>
void nhap(int a[],int n){
	for (int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
}
int main() {
    int n;
    scanf("%d",&n);
    int *a=(int *)malloc(n*sizeof(int));
	nhap(a,n);
    int dem =0;
    int i;
    int h=i+1;
    for (i=0;i<n;i++){//duyệt hết mảng
	// số min đang là ai
        int so1=a[i],so2=1,so3=i;
        for (int j=i;j<h;j++){
            if(a[j]==so1){
                so2++;
                if(so3>j){
                    so3=j;
                }
            }else if(so1>=a[j]) {
                so1=a[j];so2=1;so3=j;
            }
            if (j-i>=2){// dãy con lớn hơn 2 phần tử 
                printf("%d %d %d\n",so1,so2,so3+1);
                dem++;
                if(dem==n) {
                    return 0;
                }
            }
        }
        h++;
        if(h>=n){
        	break;
		}
    }
    return 0;
}