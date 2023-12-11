#include <stdio.h>
#include <math.h>
#include <string.h>
struct thisinh{
	char hoten[30];
	float diem;
	int truong;
};typedef struct thisinh THISINH;
void nhap_nhieu(THISINH *ts,int n){
	for(int i=1;i<=n;i++){
		printf("\nNhap thi sinh %d:\n",i);
	    printf("\nNhap ho ten:");
	   fflush(stdin);
	   fgets((*ts).hoten,sizeof ((*ts).hoten),stdin);
	   printf("\nNhap diem :");
	   scanf("%f",&(*ts).diem);
       (*ts).truong=i;
	}
}
void in_nhieu(THISINH ts[],int n){
	for (int i=1;i<=n;i++){
		printf("\nThi sinh thu %d:",i);
		printf("\nTen thi sinh:%s",ts[i].hoten);
	    printf("\nDiem:%.2f",ts[i].diem);
        printf("\nTruong:%d",ts[i].truong);
	}
}
void tong_diem(THISINH ts[],int n,int *k){
	printf("\nNhap truong k:");
	scanf("%d",k);
	float tong=0;
	for (int i=1;i<=n;i++){
		if(ts[i].truong==*k)
		tong+=ts[i].diem;
	}
	printf("\nTong diem truong:%.2f",tong);
}
void swap(THISINH *a,THISINH *b){
	THISINH tam=*a;
	*a=*b;
	*b=tam;
}
void giam_dan(THISINH ts[],int n){
	for (int i=1;i<n;i++){
		for (int j=i+1;j<=n;j++){
		   if(ts[i].diem<ts[j].diem){
		   	swap(&ts[i],&ts[j]);
		   }	
		}
	}
	printf("\nSap xep diem theo huong tang dan:\n");
	in_nhieu(ts,n);
}
void tong_diem_tung_truong(THISINH ts[],int n){
	float tong;
    int k=1;
    float res=0;
    int vitri=1;
	for(int i=1;i<=n;i++){
		tong=0;
	   if(ts[i].truong==k){
	   	tong+=ts[i].diem;
	   }
	   if(res<tong){
	   	res=tong;
	   	vitri=i;
	   }
	   printf("\nTong diem truong %d la :%.2f",k,tong);
	   k++;
	}
}

int main(){
    int n;
    int k;
    printf("\nNhap so thi sinh:");
    scanf("%d",&n);
    THISINH ts[100];
    nhap_nhieu(ts,n);
    in_nhieu(ts,n);
 //   tong_diem(ts,n,&k);
 //   giam_dan(ts,n);
    tong_diem_tung_truong(ts,n);
    return 0;
}