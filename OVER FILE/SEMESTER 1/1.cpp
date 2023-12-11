#include<stdio.h>
#include<math.h>
int main(){
	int n,x;
	printf("Nhap vao n voi x: ");
	scanf("%d%d ",&n,&x);
	int a[n];
	for(int i=1;i<=n;i++){
		printf("");
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		printf("Day vua nhap la: %d ",a[i]);
	}
	int s1=0;
	int s2=0;
	for(int i=1;i<=n;i+2){
		for(int j=i+1;j<=n;j++){
			if((a[i]+a[j]==x)){
				s1=s1+a[i];
				s2=s2+a[j];
			}
		}
	}
	printf("%d %d ",s1,s2);
}