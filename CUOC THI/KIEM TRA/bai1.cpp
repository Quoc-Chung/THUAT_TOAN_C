#include<stdio.h>
#include<math.h>
#include<stdlib.h>
struct  HocSinh{
  int Ma;
  float Diem;
  char Lop;	
};
void doc (HocSinh hv[],int n){
	for (int i=0;i<n;i++ ){
		scanf("%d",&hv[i].Ma);	
		scanf("%f",&hv[i].Diem);
	    scanf("%c",&hv[i].Lop);
	}
	int dem=0;
	for (int i=0;i<n;i++){
		if(hv[i].Ma%5==0 && (hv[i].Lop=='B' || hv[i].Lop=='C')){
			dem++;
		}
	}
	printf("%d",dem);
	for (int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(hv[i].Diem <hv[j].Diem){
				HocSinh tmp=hv[i];
				hv[i]=hv[j];
				hv[j]=tmp;
			}
		}
		for(int i=0;i<n;i++){
			printf("\n%d",hv[i].Ma);
		}
	}
}
int  main (){
	int n;
	scanf("%d",&n);
	HocSinh hv[100];
	doc(hv,n);
	return 0;
}