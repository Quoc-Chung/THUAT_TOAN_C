//Bài 1-8 Cho tệp văn bản input.txt chứa thông tin về hai dãy a1, a2, ..., an và b1, b2. .. bm. 
//Tệp có cấu trúc như sau: Dòng đầu chứa số nguyên n, m là số phần tử của dãy a và dãy b. 
//dòng thứ hai chứa n số cua dãy a. Dòng thứ ba chứa m số của dãy b. Viết chương trình có 
//xây dựng các hàm để thực hiện: 
//1. Nhập vào hai dây số nguyên a và b. 
//2. Tính giá trị nhỏ nhất của dãy a và giá trị nhỏ nhất của dãy b. 
//3. Kiểm tra xem từng dãy a và b có gồm toàn các số chẵn hay không.
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
void  DocFile(int **a,int **b,int &n,int &m,char *tentep){
    FILE *f;
    f=fopen(tentep,"r");
	if(f==NULL){ 
	printf("\nKhong the  mo duoc file .");
	exit(0);
}
fscanf(f,"%d%d",&n,&m);
	*a=(int *) malloc (n*sizeof(int));
	*b=(int *) malloc (m*sizeof(int));
	for (int i=0;i<n;i++){
		fscanf(f,"%d",&((*a)[i]));
	}
		for(int i=0;i<m;i++){
		fscanf(f,"%d",&((*b)[i]));
	}
	printf("\nCac day so nguyen doc tu tep la: ");
	printf("\nMang  a la :");
	for(int i=0;i<n;i++){
		printf("%d ",(*a)[i]);
	}
	printf("\nMang  b la :");
	for(int i=0;i<m;i++){
		printf("%d ",(*b)[i]);
	}
}
void  Min(int *a,int *b,int n,int m){
	int min1=INT_MAX,min2=INT_MAX;
	for (int i=0;i<n;i++){
		if(min1>a[i]) min1=a[i];
	}
	for(int i=0;i<m;i++){
	if(min2>b[i]) min2=b[i];
	}
	printf("\nGia tri min cua day a la :%d \nGia tri min cua day  b la  :%d",min1,min2);
}
void  ToanChan(int *a,int *b,int n,int m){
	bool  flag1=true,flag2=true;
    for  (int i=0;i<n;i++){
    	if(a[i]%2!=0){
    		flag1=false;
    		break;
		}
	}
	for (int i=0;i<m;i++){
		if(b[i] %2!=0){
			flag2=false;
			break;
		}
	}
	if(flag1){
		printf("ưnDay a toan chua so chan");
	}
	else {
		printf("\nDay  a chua ca so le.");
	}
	
	if(flag2){
		printf("\nDay b toan chua so chan.");
	}
	else {
		printf("\nDay b chua ca  so le .");
	}
}
int main (){
	int n,m;
	char  tentep[50]="input.txt";
	int *a,*b;
	DocFile(&a,&b,n,m,tentep);
    Min(a,b,n,m);
    ToanChan(a,b,n,m);
	return 0;
}