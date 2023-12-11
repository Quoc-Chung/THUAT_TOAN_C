#include<stdio.h>
#include<math.h>
int main(){
	int n;
	scanf("%d",&n);
	int a[n];
	for(int i=1;i<=n;i++)
	{
	scanf("%d",&a[i]);
	}
	printf("\nDay So La :\n");
	 for(int i=1;i<=n;i++)
	 {
	 	printf(" %d",a[i]);
     }
     float max=0;
     int d=n;
     for (int i=1;i<=n;i++){
     		float x=(float)a[i]/(float)d;
     		d--;
     		if(max<x){
     			max=x;
			 }
		 }
	printf("\nGia tri max la :%.2f",max);
}