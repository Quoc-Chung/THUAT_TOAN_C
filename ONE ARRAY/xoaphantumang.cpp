#include <stdio.h>
#include <math.h>
void nhapmang(int a[],int &n){//truyền &n mới nhập được số n ở trong hàm 
	do {
		printf("Nhap n:");
		scanf("%d",&n);
		if(n<0){
			printf("\nYeu cau nhap lai:\n");
		}
	}while (n<0);//condition while trùng với condition if.
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
}
void inmang(int a[],int n){
	printf("\t\t\tMang la :\n");
	for (int i=1;i<=n;i++){
		printf("%d ",a[i]);
	}
}
// chi so:1 2 3   4 5 6 7
// ptu   :2 3 4   5 6 7 8
// ta thêm xóa 1 phần tử trong mảng : ví dụ xóa phần tử ở vị trí thứ 4 tức là xóa a[4]=5;
// chi so:1 2 3   4 5 6(chỉ số sẽ giảm đi một vị trí)
// p tử  :2 3 4   6 7 8(các số từ phần tử bị lược bỏ sẽ giảm đi một ô ,các số phía trước phần tử 
//bị lược bỏ vẫn giữ nguyên 
//để làm được điều này thì ta sẽ chạy vòng for từ cuối đến đầu 
//n=7
//a[4]=a[5];
//a[5]=a[6];
//a[6]=a[7];
void xoaphantu(int a[],int &n,int vitrixoa){// vì số n sẽ thay đổi khi hàm kết thức nên ta phải truyền địa chỉ 
	for (int i=vitrixoa;i<=n-1;i++){
		a[i]=a[i+1];
	}
	n--;// vì xóa một số (chứa một vị trí trong mảng ) nên sẽ bỏ 1 vị trí đi
}
int main (){
	int n;
	int vitrixoa;
	int a[100];
	nhapmang(a,n);
	do{
		printf("\nNhap vi tri xoa:");
		scanf("%d",&vitrixoa);
		if(vitrixoa<1 || vitrixoa>n){
			printf("\nVui long nhap lai :\n");
		}
	}while (vitrixoa<1 || vitrixoa>n);
	xoaphantu(a,n,vitrixoa);
	inmang(a,n);
	return 0;
}














