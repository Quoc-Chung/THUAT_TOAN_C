#include <stdio.h>
#include <math.h>
void  nhapmang(int a[100][100],int m,int n){
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			printf("Nhap mang a[%d][%d]:",i,j);
		 scanf("%d",&a[i][j]);	
		}
	}
}
void inmang(int a[100][100],int m,int n){
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
}
// cot chan thi duyet tung cot chan một --- sau do duyet tu hang dau den hang cuoi 
void tongcotchan (int a[100][100],int m,int n){
	int cotchan;
	for (int j=0;j<n;j+=2){
		cotchan=0;
		for (int i=0;i<m;i++){
			cotchan +=a[i][j];
		}
		printf("%d ",cotchan);
	}
}
// kiem tra co phai ma tran tam giac tren khong 
void kiemtrathu(int a[100][100],int m,int n){
	int flag=0;
	for (int i=0;i<m;i++){
		for (int j=i+1;j<=n;j++){
			 if(i<j && a[i][j]!=0){
			
		flag++;
      }
  }
}
		if(flag==0){
printf("\nMa tran la ma tran tam giac tren\n");
}
else{
	printf("\nMa tran khong la tam giac tren");
}
}
// tong tung hang la duyet tung hang mot ,sau do duyet tu cot 1 den cot cuoi ;
void tongtunghang(int a[100][100],int m,int n){
	for (int i=0;i<m;i++){
		int tong=0;
		for (int j=0;j<n;j++){
			tong +=a[i][j];
		}
		printf("\n%d",tong);
	}
}
int main (){
	
	int m,n;
	printf("Kich thuoc:\n");
	scanf("%d%d",&m,&n);
	int a[100][100];
	nhapmang(a,m,n);
	printf("\nIn mang :\n");
	inmang(a,m,n);
//	printf("\nTong cac cot chan la :\n");
	//tongcotchan(a,m,n);
 kiemtrathu(a,m,n);
//	printf("\nTong tung hang cua ma tran la :\n");
//tongtunghang(a,m,n);

	return 0;
}