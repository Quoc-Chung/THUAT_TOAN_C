#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
struct  ToaDo{
	float hoanh;
	float tung;
};
void DocFile(ToaDo **t,int &n,char *tentep){
	FILE *f=fopen(tentep,"r");
	if(f==NULL){
		printf("\nKhong the  mo duoc file.");
		exit(0);
	}
	fscanf(f,"%d",&n);
	(*t)=(ToaDo *)malloc(n*sizeof(ToaDo));
	for(int i=0;i<n;i++){
		fscanf(f,"%f%f",&(*t)[i].hoanh,&(*t)[i].tung);
	}
	printf("\nToa do day  diem la :\n");
	for (int i=0;i<n;i++){
		printf("\n%.2f  %.2f",(*t)[i].hoanh,(*t)[i].tung);
	}
}
void XaNhat(ToaDo *t,int n){
	float hoanh=0,tung=0;
	float  max=-1e8;
	for (int i=0;i<n;i++){
		if(max < sqrt(pow(t[i].hoanh,2)+pow(t[i].tung,2))){
			max < sqrt(pow(t[i].hoanh,2)+pow(t[i].tung,2));
			hoanh=t[i].hoanh;
			tung=t[i].tung;
		}
	}
	printf("\nToa  do  xa nhat goc toa do :%.2f %.2f",hoanh,tung);
}
// tinh  do dai  duong  gap khuc  
void DoDai(ToaDo *t,int n){
	float dodai=0;
	for (int i=2;i<n-2;i++){
	  	dodai+=sqrt(pow(t[i+1].hoanh-t[i].hoanh,2)+pow(t[i+1].tung-t[i].tung,2));
	}
	dodai+=sqrt(pow(t[0].hoanh-t[n-1].hoanh,2)+pow(t[0].tung-t[n-1].tung,2));
	printf("\nDo dai gap khuc :%.2f",dodai);
}
int main(){
	int n;
	ToaDo *t;
	char  tentep[50];
	printf("\nNhap ten tep:");
	gets(tentep);
	DocFile(&t,n,tentep);
	XaNhat(t,n);
	DoDai(t,n);
	return 0;
}