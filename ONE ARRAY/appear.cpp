#include <stdio.h>
#include <math.h>
void nhap(int a[],int n){
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
}
int main(){
	int n;
	scanf("%d",&n);
	int a[n];
	nhap(a,n);
	for (int i=1;i<=n;i++){// duyet phan tu tu dau mang den cuoi mang
	  int flag=0;//tao co danh dau
	  for (int j=1;j<i;j++){// duyet cac so dung truoc so ta xet 
	  	if(a[i] == a[j]){
	  		flag=1;
	  		break;//neu gap so dâ xuat hien phia truoc thi dung vong lap luon
		  }
	  }
	  // kiem tra neu so a[i] chua  xuat hien thi in ra so a[i] do va ta van duyet so do trong vong for i
		if(flag==0){
			printf("%d ",a[i]);
		}
	}
}