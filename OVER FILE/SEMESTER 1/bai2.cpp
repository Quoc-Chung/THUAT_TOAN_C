
//Tính và in ra màn hình
   //      S=sqrt( a1/n+ a2/n-1+ … an/1)
//Kiểm tra xem có dãy đối xứng không (a1=an, an=an-1, a3=an-1
#include <stdio.h>
#include <math.h>
// ve bieu do tinh giai thua 
int gt(int n){
	int gt=1;
	for (int i=1;i<=n;i++){
		gt *=i;
	}
	return gt;
}
void nhapin(int x[],int n){
	for (int i=1;i<=n;i++){
		scanf("%d",&x[i]);
	}
	printf("Day la :\n");
	for (int i=1;i<=n;i++){
		printf("%d ",x[i]);
	}
}
//Tính và in ra màn hình
//S=sqrt( a1/n+ a2/n-1+ … an/1)
void calculate(int  a[],int n){
	float S=0;
	for (int i=1;i<=n;i++){
		for (int j=n;j>=1;j--){
			S+=a[i]/j;
		}
	}
	float x=sqrt(S);	
	printf("\nGia tri vua tinh la :%.2f",x);
}
void doixung(int a[],int n){
	int flag=0;
	for(int i=1;i<=(n/2);i++){
		for (int j=n;j>=(n/2);j--){
			if(a[i]!=a[j]){
				flag++;
			}
		}
	}
	if(flag==0){
		printf("\nDay doi xung.");
	}
	if(flag>0) {
		printf("\nDay khong doi xung");
	}
}
int main (){
//	int n;
//	printf("Nhap n:");
//   scanf("%d",&n);
//   printf("Giai thua cua so n la :%d",gt(n));
    int n;
    printf("Nhap n:");
    scanf("%d",&n);
    int  a[n];
    nhapin(a,n);
    //calculate(a,n);
    doixung(a,n);
    return 0;
}