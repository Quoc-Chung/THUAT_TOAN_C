#include <stdio.h>
#include <math.h>
#include <stdlib.h>
void nhap(int a[],int n){
	for (int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
}
void in(int a[],int n){
	for (int i=0;i<n;i++){
		printf("%d ",a[i]);
	}
}
int main (){
	FILE *f;
	// open file  
	f=fopen("mangdoc.txt","r");
	// check open file 
	if(f==NULL){
		printf("\nFIlE khong mo duoc ");
	}
	int n;
	fscanf(f,"%d",&n);
	printf("\nGia tri cua  n la :%d",n);
	int a[n];
	for (int i=0;i<n;i++){
		fscanf(f,"%d",&a[i]);
	}
	printf("\nGia tri cua mang la :\n");
	for (int i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	// close file 
	fclose (f);
}