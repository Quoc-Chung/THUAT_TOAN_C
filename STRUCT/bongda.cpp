#include <stdio.h>
#include <math.h>
#include <string.h>
void delete_newline(char c[]){
	size_t len=strlen(c);
	if(c[len-1]=='\n'){
		c[len-1]='\0';
	}
}
struct bongda{
	char ten[30];
	int ban;
	char doibong[2];
};
void nhap (bongda ct[],int n){
	for (int i=1;i<=n;i++){
		printf("Nhap cau thu %d:\n",i);
		printf("Nhap ho va ten :");
		fflush(stdin);
		fgets(ct[i].ten,sizeof(ct[i].ten),stdin);
		printf("\nNhap ban thang:");
		scanf("%d",&ct[i].ban);
		printf("\nNhap doi bong:");
		fflush(stdin);
		fgets(ct[i].doibong,sizeof(ct[i].doibong),stdin);
	}
}
void in(bongda ct[],int n){
	for (int i=1;i<=n;i++){
	   printf("\nCau thu thu %d:",i);
	   delete_newline(ct[i].ten);
	   printf("\t Ho va ten:%s",ct[i].ten);
	   printf("\tBan thang:%d",ct[i].ban);
	   delete_newline(ct[i].doibong);
	   printf("\tDoi bong:%s",ct[i].doibong);
	}
}
void total(bongda ct[],int n){
	int sum1=0,sum2=0,sum3=0,sum4=0;
	char doi1[2]="A",doi2[2]="B",doi3[2]="C",doi4[2]="D";
	for (int i=1;i<=n;i++){
		if(strcmp(ct[i].doibong,doi1)==0){
			sum1+=ct[i].ban;
		}
		if(strcmp(ct[i].doibong,doi2)==0){
			sum2+=ct[i].ban;
		}
		if(strcmp(ct[i].doibong,doi3)==0){
			sum3+=ct[i].ban;
		}
		if(strcmp(ct[i].doibong,doi4)==0){
			sum4+=ct[i].ban;
		}
	}
	printf("\nSo ban thang tung doi la:\n");
	printf("\nDoi A:%d",sum1);
	printf("\nDoi B:%d",sum2);
	printf("\nDoi C:%d",sum3);
	printf("\nDoi D:%d",sum4);
	
}
void list(bongda ct[],int n){
	for (int i=1;i<n;i++){
		for (int j=i+1;j<=n;j++){
			if(ct[i].ban>ct[j].ban){
			
			bongda tam=ct[i];
			ct[i]=ct[j];
			ct[j]=tam;
		}
	}
	}
	printf("\nDanh sach sinh vien theo ban thang tang dan :");
	for (int i=1;i<=n;i++){
		printf("\n%d.%s",i,ct[i].ten);
	}
}
int main (){
	int n;
	printf("Nhap so cau thu:");
	scanf("%d",&n);
	bongda ct[100];
	nhap(ct,n);
	in(ct,n);
	total(ct,n);
	list(ct,n);
	
	return 0;
}