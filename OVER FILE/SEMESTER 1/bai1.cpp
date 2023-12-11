
#include <stdio.h>
#include <math.h>
// Viết thuật toán tìm UCLN của hai số nguyên dương.
int ucln(int a,int b){
	if(a==0 || b==0){
		return a+b;
	}
	while (a!=b){
		if(a>b){
			a=a-b;
		}
		else {
		    b=b-a;
		}
		
	}
	return a;
}
int uclndequy(int a,int b){
	if(b==0){
		return a;
	}
	return ucln(b,a%b);
}
// Nhập dãy số nguyên in ra màn hình
void nhapin(int x[],int n){
	for (int i=1;i<=n;i++){
		scanf("%d",&x[i]);
	}
	printf("Day la :\n");
	for (int i=1;i<=n;i++){
		printf("%d ",x[i]);
	}
}
//Dãy số tăng dần
void tangdan(int a[],int n){
	int tam;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			if(a[i]<a[j]){
			tam=a[i];
			a[i]=a[j];
			a[j]=tam;
		}
		}
	}
	printf("\nDay tang dan la :\n");
	for (int i=1;i<=n;i++){
		printf("%d ",a[i]);
	}
}
// Đếm xem có bao nhiêu bộ 2 số liên tiếp(ai, ai+1) mà có cùng tính chất chẵn lẻ mà số sau lớn số trước.
void demboso(int a[],int n){
	int dem =0;
	for (int i=1;i<n;i++){
		if((a[i]%2==0 && a[i+1]%2==0 && a[i]<a[i+1]) || 
		      (  a[i]%2==1 && a[i+1]%2==1 && a[i]<a[i+1])){
		      	dem++;
			  }
	}
	printf("\nSo cap thoa man la :%d",dem);
}
//test case : 1 3 2 3 5 4 6  ==>> 3cap
//           2 3 5 4 1 2 8 6 ==> 2 cap


int main (){
//	int a,b;
//	printf("Nhap hai so a va b:");
//	scanf("%d%d",&a,&b);
//	printf("%d",ucln(a,b));
//printf("UCLN la: %d",uclndequy(a,b));
    int n;
    printf("Nhap n:");
    scanf("%d",&n);
    int a[n];
    nhapin(a,n);
   tangdan(a,n);
   demboso(a,n);
    
    return 0;
}