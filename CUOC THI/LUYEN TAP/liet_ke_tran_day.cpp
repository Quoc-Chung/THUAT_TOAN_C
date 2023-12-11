#include <stdio.h>
#include <math.h>
#include <stdlib.h>
void nhap(int a[],int n){
	for (int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
}
void kiem_tra(int a[],int n){
	// dòng đầu 
	int flag=0,flag1=0;
	for (int i=0;i<n;i++){
		if(a[i]%2!=0){
			printf("%d ",a[i]);
			flag++;
		}
	}
	if(flag==0){
		printf("\nDay khong co so le");
	}
	// dòng thứ  hai
	printf("\n");
	for (int i=0;i<n;i++){
		if(a[i]%5 == 2 || a[i]%7 == 3){
			printf("%d ",a[i]);
			flag1++;
		}
	}
	if(flag1==0){
		printf("\nDay khong co so chia nam du hai hoac chia bay du ba");
	}
	if(n<3){
       printf("\nDay khong co bo ba lien tiep cap so cong");
	}
	else{
		int dem=0;
	//a[1]-a[0]=a[2]-a[1]
		for (int i=0;i<n-2;i++){
			if(a[i+1]-a[i]==a[i+2]-a[i+1]){
			 printf("\n%d %d %d",a[i],a[i+1],a[i+2]);
			 dem++;	
			}
		}
		if(dem==0){
			printf("\nDay khong co bo ba lien tiep cap so cong");
		}
	}
}
int main (){
	int n;
    scanf("%d",&n);
    int *a=(int*) malloc(n*sizeof(int));
    nhap(a,n);
    kiem_tra(a,n);
    free(a);
    return 0;
}