#include <stdio.h>
#include <math.h>
void nhapmang(int a[],int n){
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
}
void inmang(int a[],int n){
	printf("\nMang in ra la :\n");
	for (int i=1;i<=n;i++){
		printf("%d ",a[i]);
	}
}
// tìm kiếm phần tử vét cạn =>> ta phải duyệt sạch sẽ các phần tử không xót một phần tử nào(vét cạn)
void timkiemphantuvetcan(int a[],int n,int x){
	int flag=0;
	int vitri;
	printf("\nCsc vi tri ton tai  so bang x:\n");
	for (int i=1;i<=n;i++){
		vitri=0;
		if(a[i]==x){
			
			vitri=i;
			printf("\n%d",vitri);
	     flag++;
	}
	}
	if(flag==0){
		printf("\nKhong co gia tri nao bang x");
	}
}
// tìm kiếm tuần tự lính canh thong thuong no se di với việc đặt cờ hiệu 
void timkiemtuantulinhcanh(int a[],int n,int x){
	a[n]=x;// ta đưa x vào cuối mảng để canh  các số đứng trước nó nếu thỏa mãn sẽ đổi lính canh
	for (int i=1;i++){
		if(a[i]==x){
		 return i;// in ra vi trí số  trong mảng có giá trị bằng x	
		}
	}
}
// hàm chính :
//int vitri=timkiemtuantulinhcanh(a,n,x);
//if(vitri==n){tức là vị trí nó không bị thay đổi từ đầu đến cuối vẫn ở cuối cùng
//	printf("\nKhong co gia tri nao ton tai.");
//}
//else{
//	printf("\nSo bang x ton tai o vi tri :%d",vitri);
//}
int main (){
	int n;
	printf("Nhap n:");
	scanf("%d",&n);
	int a[n];
	nhapmang(a,n);
	inmang(a,n);
	int x;
	printf("\nNhap x:");
	scanf("%d",&x);
	timkiemphantuvetcan(a,n,x);
}