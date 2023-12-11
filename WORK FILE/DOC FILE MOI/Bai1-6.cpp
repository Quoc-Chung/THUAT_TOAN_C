//Bài 1-6 Cho tệp văn bản input.txt chứa thông tin về hai dãy a1, a2, .... an và b1m b2. .... 
//bn. Tệp có cấu trúc như sau: Dòng đầu chứa các số nguyên n, m là số phân tử của dãy a và 
//dãy b. dòng thứ hai chứa n số của dãy a, dòng thứ ba chứa m số của dãy b. Hãy viết chương 
//trình có xây dựng các hàm để thực hiện:
//1. Đọc từ tệp hai dãy số nguyên a1, a2, ..., a và b1, b2, ... bm. 
//2. Tính giá trị lớn nhất của dãy a và giá trị lớn nhất của dãy b. 
//3. Sắp xếp dãy a và dãy b đều theo thứ tự giảm dần, sau đó đưa các dãy số dã được sắp 
//xếp ra màn hình
#include<bits/stdc++.h>
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
void  Max(int *a,int *b,int n,int m){
	int max1=INT_MIN,max2=INT_MIN;
	for (int i=0;i<n;i++){
		if(max1<a[i]) max1=a[i];
	}
	for(int i=0;i<m;i++){
		if(max2<b[i]) max2=b[i];
	}
	printf("\nGia tri max cua day a la :%d \nGia tri max cua day  b la  :%d",max1,max2);
}
int cmp(const void *a, const void *b) {
    int *x = (int *)a;
    int *y = (int *)b;
    return *y-*x;
}
void SapXep(int  *a,int *b,int n,int m){
    qsort(a, n, sizeof(int), cmp);
    qsort(b, m, sizeof(int), cmp);
		printf("\nDay a giam dan la :\n");
	for(int i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	printf("\nDay a giam dan la :\n");
	for(int i=0;i<m;i++){
		printf("%d ",b[i]);
	}
}
int main (){
	int n,m;
	char  tentep[50]="input.txt";
	int *a,*b;
	DocFile(&a,&b,n,m,tentep);
	SapXep(a,b,n,m);
	Max(a,b,n,m);
	return 0;
}