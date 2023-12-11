#include <stdio.h>
#include <math.h>
// tao mot mang dem
int count [1000001]={0};
void nhapmang(int a[],int n){
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
}
int main (){
 	int n;
 	scanf("%d",&n);
 	int a[n];
 	nhapmang(a,n);
 	// satisfy number :so thoa man 
 	for (int i=1;i<=n;i++){
 	    count[a[i]]++;// tuc la neu gia tri bang nhau  cua a[i] xuat hien thi no deu tro
		 // den mot phan tu trong mang dem la count [a[i]] 
	 }
	 for (int i=1;i<=n;i++){
	 	if(count[a[i]]!=0)// tuc la neu so do chua xuat hien mot lan nao thi khong in ra 
	 	printf("\n%d %d",a[i],count[a[i]]);
	 	count[a[i]]=0;// tuc la so do xuat hien roi thi thoi khong in ra nua
		// khoi tao gia tri cua mang dem ma cac gia tri bang nhau trong mang bang nhau tro den thi khong in ra nua 
}
  return 0;	
}
 	