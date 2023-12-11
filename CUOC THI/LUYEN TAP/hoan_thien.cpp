#include <stdio.h>
#include <math.h>
#include <stdlib.h>
void nhap(int a[],int n){
	for (int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
}
bool  nguyen_to(int n){
	if(n<2){
		return false;
	}
	else {
		for (int i=2;i<=sqrt(n);i++){
			if(n%i==0){
				return false;
			}
		}
	}
	return true;
}
bool hoan_hao(int n){
    int sum_uoc=0;
    for (int i=1;i<n;i++){
        if(n%i==0){
            sum_uoc+=i;
        }
    }
    if(n==sum_uoc){
        return true;
    }
    else {
        return false;
    }
}
void kiem_tra_day(int a[],int n){
	int flag=0;
	printf("\nCac so vua la nguyen to vua la hoan hao:\n");
	for (int i=0;i<n;i++){
		if(nguyen_to(a[i])==true && hoan_hao(a[i])==true){
			printf("%d ",a[i]);
		    flag++;
		}
		
	}
	if(flag==0){
		printf("\nKhong co so thoa man");
	}
	printf("\nCac so la nguyen to:\n");
	for (int i=0;i<n;i++){
		if(nguyen_to (a[i])==true && hoan_hao(a[i])==false){
			printf("%d ",a[i]);
		}
	}
	printf("\nCac so la so hoan hao :\n");
	for (int i=0;i<n;i++){
		if(nguyen_to (a[i])==false && hoan_hao(a[i])==true){
			printf("%d ",a[i]);
		}
	}
}
int main (){
    int n;
    scanf("%d",&n);
    int *a=(int*) malloc (n*sizeof(int ));
    nhap(a,n);
    kiem_tra_day(a,n);
    free(a);
    return 0;
}