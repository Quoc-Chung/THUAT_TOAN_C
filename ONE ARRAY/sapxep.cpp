#include <stdio.h>
#include <math.h>
int nhapmang(int a[],int n){
    for (int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
}
int sapxepchantang(int a[],int n){
   int sapxep;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            if(a[i]%2==0 && a[j]%2==0 && a[i]<a[j]){
               sapxep = a[i];
                a[i]=a[j];
                a[j]=sapxep;
            }
        }
    }
    return sapxep;
}
int swap(int a,int b){
	int tam=a;
    a=b;
    b=tam;
}
int main (){
    int n;
    scanf("%d",&n);
     int a[n];
    nhapmang(a,n);

    sapxepchantang(a,n);
     for(int i=1;i<n;i++){
        for (int j=i+1;j<=n;j++){
            if (a[j]%2==0){
                int t = a[i];
                a[i]=a[j];
                a[j]=t;
                break;
            }
        }
		}
		for (int i=1;i<=n;i++){
			printf("%d",a[i]);
	}
    }
