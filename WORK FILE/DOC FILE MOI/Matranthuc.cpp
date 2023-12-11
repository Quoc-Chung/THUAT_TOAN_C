#include<stdio.h>
#include<math.h>
void  DocMaTran(float  ***a,int &m,int &n,char *tentep){
	FILE *f;
	f=fopen(tentep,"r");
	if(f==NULL){
		printf("\nKhong  the  doc tu file.");
		exit(0);
	}
	fscanf(f,"%d%d",&m,&n);
	// cap phat dong cho một mảng con trỏ  hàng 
	 *a=(float **)malloc (m*sizeof(float*));
	 // cap phat dong  cho  cac  gia tri trong  ma tran  
   for(int i=0;i<m;i++){
   	(*a)[i]=(float*) malloc(n*sizeof(float));
   }
   //  Doc file 
    for (int  i=0;i<m;i++){
    	for(int j=0;j<n;j++){
    	fscanf(f,"%f",&((*a)[i][j]));	
		}
	}
	fclose(f);
}
void tongmatran(float  **a,int m,int n){
	float tong=0;
	int dem=0;
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			if(a[i][j] <0){
				tong +=a[i][j];dem++;
			}
		}
	}
	if(dem==0){
		printf("\nKhong  co phan tu  am  ");
	}
	else{
	printf("\nTbc  cac  phan  tu  cua ma tran la  %.2f",tong /dem);
}
	
}
void  PhanTuAm(float **a,int m,int n){
	int h=0,c=0;
	float max=INT_MIN;
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			if(a[i][j] <0 && max <a[i][j]){
				max=a[i][j];
				h=i+1;c=j+1;
			}
		}
	}
	printf("\nPhan tu am lon nhat  la  a[%d][%d]=%.2f",h,c,max);
}
int main(){
	int  m, n;
	float **a;
	char tentep[50]="matran.txt";
	char ketqua[50]="xuatmt.txt";
	DocMaTran(&a,m,n,tentep);
	tongmatran(a,m,n);
	PhanTuAm(a,m,n);	
	return 0;
}