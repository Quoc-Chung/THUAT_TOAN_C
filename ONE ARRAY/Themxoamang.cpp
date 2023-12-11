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
// chi so:1 2 3 4 5 6 7
// ptu   :2 3 4 5 6 7 8 
//==>them phan tu  9 vao vi tri thu 4 trong mang:
// chi so:1 2 3 4 5 6 7 8(chỉ số sẽ tăng thêm 1 đơn vị vì có thêm 1 phân tử )
//ptu    :2 3 4 9 5 6 7 8(bộ nhớ ở trong mảng cũng sẽ có thêm  1 chỗ
// ta cần dịch các phần tử phía sau phân tử thêm vào lên 1 đơn vị,các phần tử phía trước phần tử cần thêm sẽ giữ nguyên 
//==>ta chay từ  phía trước trở lại 
//a[vitrithem]=phan tu them
//a[5]=a[4]
//a[6]=a[5]
//a[7]=a[6]
//a[8]=a[7]
void themphantu(int a[],int &n,int vitrithem,int phantuthem){ //số n tăng thêm 1 đơn vị nên nó sẽ bị thay đổi khi hàm kết thúc
    //cho vong for chay tư a[8]=> a[vitrithem +1]
    // lam theo ve trai
	for (int i=n+1;i>=vitrithem+1;i--){
		a[i]=a[i-1];
	}
	// Lam theo ve phai 
	//for (int i=n;i>=vitrithem;i--){
	//	a[i]=a[i+1];
	n++;//để cấp phát một ô cho vừa phần tử thêm
	a[vitrithem]=phantuthem;
}
// chi so:1 2 3 4 5 6 7
// ptu   :2 3 4 5 6 7 8
// ta thêm xóa 1 phần tử trong mảng : ví dụ xóa phần tử thức 
// chi so:1 2 3 4 5 6


int main (){
	int n;
	int a[100];
	nhapmang(a,n);
	int phantuthem;
	int vitrithem;
	printf("\nNhap phan tu them :");
	scanf("%d",&phantuthem);
	do {
		printf("\nNhap vi tri them:");
		scanf("%d",&vitrithem);
		if(vitrithem<1  || vitrithem>=n){
			printf("\nVui long nhap lai vi tri them");
		}
	}while (vitrithem<1  || vitrithem>=n);
	themphantu(a,n,vitrithem,phantuthem);
	inmang(a,n);
	return 0;
	
}


















