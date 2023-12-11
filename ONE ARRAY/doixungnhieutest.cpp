#include<stdio.h>
#include<math.h>
void nhap(int a[],int n){
	printf("\nNhap mang :\n");
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
}
void in(int a[],int n){
	printf("\nMang vua nhap :\n");
	for (int i=1;i<=n;i++){
		printf("%d ",a[i]);
	}
}
void kiemtradoixung(int a[],int n){
	int giua=n/2;
	int flag=0;
	for (int i=1;i<=giua;i++){
		if(a[i]!=a[n]){
			flag++;
			break;
		}
		n--;
	}
	if(flag==0){
		printf("\nMang la mang doi xung .");
	}
	else{
		printf("\nMang khong doi xung.");
	}
}
int main(){
//	int t;
//	printf("\nNhap test case :");
//	scanf("%d",&t);
//	while (t--){
	int n;
	printf("\nNhap n:");
	scanf("%d",&n);
	int a[n];
	nhap(a,n);
	kiemtradoixung(a,n);
//}
	//in(a,n);
	return 0;
}
