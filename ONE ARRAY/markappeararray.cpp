#include <stdio.h>
#include <math.h>
int mark[1000001]={0};// khoi tao mang danh dau ra ngoai de tranh tran bo nho
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
	for (int i=1;i<=n;i++){
		if(mark[a[i]]==0){// tức là mới  xét nó lần đầu ,not mark it 
		printf("%d ",a[i]);
		mark[a[i]]=1;// đánh dâu nó da xuat hien roi 
		}
	}
}
// bài này còn một cách trâu bò hơn là ta sẽ duyet mang :
//duyet  các chỉ so dung truoc no neu xuat hien roi thi khong in ra 
//con neu chua xuat hien thi in ra cua no 
// tên bai :appear.cpp