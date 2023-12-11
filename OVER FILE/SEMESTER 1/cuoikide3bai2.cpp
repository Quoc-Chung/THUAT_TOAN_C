#include <stdio.h>
#include <math.h>
struct cauthu{
	char hoten[30];
	int SBT;
	int phut;
	int tienthuong;
};
void nhap (struct cauthu ct[],int n){
	for (int i=1;i<=n;i++){
		printf("CAU THU %d:\n",i);
		printf("Nhap ho ten:");
		fflush (stdin);
		fgets(ct[i].hoten,sizeof(ct[i].hoten),stdin);
		printf("\nNhap SBT:");
		scanf("%d",&ct[i].SBT);
		printf("\nSo phut thi dau :");
		scanf("%d",&ct[i].phut);
	}
}
void in (struct cauthu ct[],int n){
	printf("\t\t\t\tTHONG TIN CAU THU ");
	for (int i=1;i<=n;i++){
	  printf("\nCau thu thu %d:\n",i);
	  printf("\nHo va ten:%s",ct[i].hoten);
	  printf("\nSo ban thang :%d",ct[i].SBT);
	  printf("\nSo phut thi dau:%d",ct[i].phut); 	
	}
}
void tienthuong (struct cauthu ct[],int n){
	int vitri;
	for (int i=1;i<=n;i++){
		ct[i].tienthuong=0;
		vitri=0;
		if(ct[i].phut>=500 && ct[i].SBT>=3){
			ct[i].tienthuong=50;
			vitri=i;
		printf("\n%s co tien thuong: %d trieu dong",ct[vitri].hoten,ct[i].tienthuong);
		continue;	
		}
	    if(ct[i].phut>=500 || ct[i].SBT>=3 ){
			ct[i].tienthuong=20;
			vitri=i;
		printf("\n%s co tien thuong:%d trieu dong",ct[vitri].hoten,ct[i].tienthuong);
		continue;
		}
	    if(ct[i].phut<500 && ct[i].SBT<3){
	    	vitri=i;
	    printf("\nCau thu %s khong co tien thuong ",ct[vitri].hoten);
		continue;
		}
	}
}
void tienthuongmax(struct cauthu ct[],int n){
	printf("\nDANH SACH CAU THU CO TIEN THUONG NHIEU NHAT :\n");
	int max=-1;
	for (int i=1;i<=n;i++){
		if(max<=ct[i].tienthuong){
			max=ct[i].tienthuong;
		}
	}
	   int vitri;
	   for (int i=1;i<=n;i++){
	   	vitri=0;
	   	if(ct[i].tienthuong==max){
	   	     vitri=i;
			printf("%s",ct[vitri].hoten);	
		   }
	   }
}
int main (){
	int n;
	printf("Nhap n:");
	scanf("%d",&n);
	struct cauthu ct[100];
	nhap(ct,n);
	//in(ct,n);
	tienthuong(ct,n);
	tienthuongmax(ct,n);
	return 0;
}
