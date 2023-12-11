#include <stdio.h>
#include <math.h>
int nguyento(int n){
	if(n<2){
		return 0;
	}
	else{
	for (int i=2;i<=sqrt(n);i++){
		if(n%i==0)
		return 0;
	}
}
	return 1;
}
void nhapmang(int a[],int n){
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
}
void inmang(int a[],int n){
	for (int i=1;i<=n;i++){
		printf("%d ",a[i]);
	}
}
void nguyentocungnhau(int a[],int n){
	int dem=0;
	for (int i=1;i<=n;i++){
		if(nguyento(a[i]) && nguyento(a[i+1])){
			dem++;
		}
	}
	printf("\nCac cap so nguyen  to cung nhau :%d",dem);
}

void daycondainhat(int a[],int n){
	int dem=1;// day con ban dau no luon bang 1 roi nen dem=1
	int max=0;
	for (int i=1;i<=n;i++){
		if(a[i]==a[i+1]){
			dem++;
			if(max<dem){
				max=dem;
			}
	    }
	 	else{
	 		dem=1;// reset lai bien count
		 }
	}
  printf("\nDo dai day con  dai nhat :%d",max);
}
void daytangdainhat(int a[],int n){
	int dem=1;// day con ban dau no luon bang 1 roi nen dem=1
	int max=0;
	for (int i=1;i<=n;i++){
		if(a[i]<a[i+1]){
			dem++;
			if(max<dem){
				max=dem;
			}
	    }
	 	else{
	 		dem=1;// reset lai bien count
		 }
	}
  printf("\nDo dai day con  dai nhat :%d",max);
}
int count_equal_double(int a[],int n){
	int dem=0;
	for (int i=1;i<=n;i++){
		if(a[i]==a[i+1]){
			dem++;
		}
	}
//	printf("\n%d",dem);
   return dem;
}
int main (){
	int t,b[100];
	scanf("%d",&t);
	while (t--){
	int n;
	do {
	printf("Nhap so n:");
	scanf("%d",&n);
	if(n<1){
		printf("\nVui long nhap lai ");
	}
	}while(n<1);
	int a[n];
	printf("\nNhap mang:\n");
	nhapmang(a,n);
  for (int i=1;i<=t;i++){
  	b[i]=count_equal_double(a,n);
  }
	//inmang(a,n);
	
	//nguyentocungnhau(a,n);
	//daycondainhat(a,n);
//	daytangdainhat(a,n);
}
for (int i=1;i<=t;i++){
	printf("nKet qua la :\n");
	printf("\n%d ",b[i]);
}
}