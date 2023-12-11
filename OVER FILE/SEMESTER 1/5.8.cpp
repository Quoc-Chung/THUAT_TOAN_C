#include <stdio.h>
#include <math.h>
void nhapmang (int a[100][100],int n){
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			scanf("%d",&a[i][j]);
		}
	}
}
void inmang(int a[100][100],int n){
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
}
int minmotmang(int a[],int n){
	int min=a[1];
	int vitri;
	for (int i=1;i<=n;i++){
		if(min>=a[i]){
			min=a[i];
			vitri=i;
		}
	}
	return vitri;
	
}
// kiem tra ma tran 
void kiemtrathu(int a[100][100],int n){
	for (int i=0;i<n;i++)
		for (int j=i+1;j<=n;j++)
			 if(i>j && a[i][j]==0){
			 	printf("\nMa tran tren la ma tran tam giac tren\n");
			 }
			 else{
			 	printf("\nMa tran tren khong phai la ma tran tam giac tren");
}
}
void cottichmin(int a[100][100],int n){
	int b[100];
	int tich;
	for (int j=0;j<n;j++){
		tich=0;

	for (int i=0;i<n;i++){
		tich *=a[i][j];
	}
	for (int k=1;k<=n;k++){
	 b[k]=tich;	
	}
}
  int vitri=minmotmang(b,n);
printf("\nVi tri cot co tich min la :%d",vitri);	
}
int cheophu(int a[100][100],int n){
	int tong=0;
	for(int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			if(j==n-1-i || i==n-1-j){
				tong+=a[i][j];
			}
		}
	
	}
	return tong ;
	}
int cheochinh(int a[100][100],int n){
	int tong=0;
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			if(i==j){
				tong+=a[i][j];
			}
		}
	}
	return tong;
}
///////////////
int tongtunghang(int a[100][100],int n){
	int tong;
   int chinh=cheochinh(a,n);
	int flag=0;
	for (int i=0;i<n;i++){
		tong=0;
		for (int j=0;j<n;j++){
			tong+=a[i][j];
		}
		if(chinh==tong){
		flag=1;
		}
		else{
     	flag=0;
		break;
		}
	}
	if(flag=0){
		return 0;
	}
	else {
		return 1;
	}
} 
//
//
//
//
int tongtungcot(int a[100][100],int n){
	int tong;
    int phu= cheophu(a,n);
	int flag1=0;
	for (int j=0;j<n;j++){
		tong=0;
		for (int i=0;i<n;i++){
			tong+=a[i][j];
		}
		if(phu==tong){
			flag1=1;
		}
		else {
			flag1=0;
		}
	}
	if(flag1==0){
		return 0;
	}
	else {
		return 1;
	}
}

// ta lai biet them cach kiem tra dieu kien tam giac 
void matrantamgiac(int a[100][100],int n){
 int flag=0;
 for (int i=0;i<n;i++){
 	for (int j=0;j<n;j++){
 		if(i>=0 && i<j && j<n){
 			if(a[i][j]==0){
 				flag=1;
			 }
		 }
		 else if(j>=0 && j<i && i<n){
		 	if(a[i][j]== 0){
		 		flag=2;
			 }
		 }
	 }
 }
 if(flag==1){
 	printf("\nMa tran tam giac tren");
 }
 else if(flag=2){
 	printf("\nMa tran tam giac duoi");
 }
 else {
 	printf("\nKhong la ma tran nao ca");
 }
}
int main(){
	int n;
	printf("Ma tran cap: ");
	scanf("%d",&n);
	int a[100][100];
	nhapmang(a,n);
	printf("Ma tran la :\n");
	inmang(a,n);
    cottichmin(a,n);
	int chinh=cheochinh(a,n);
	int phu=cheophu(a,n);
	
	if(tongtunghang(a,n)==1  && tongtungcot(a,n)==1 && chinh==phu){
		printf("\nMa tran ma phuong !");
	}
	else {
		printf("\nMa tran khong la ma tran ma phuong.");
	}
	matrantamgiac(a,n);
 printf("\nhttps://www.facebook.com/dungsi.chung.31");
}
	