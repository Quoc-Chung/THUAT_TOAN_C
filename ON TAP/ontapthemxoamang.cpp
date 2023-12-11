#include <stdio.h>
#include <math.h>
void nhapmang(int *a,int n){
	for (int i=1;i<=n;i++){
		scanf("%d",(a+i));
	}
}
void inmang(int *a,int n){
	printf("\nMang vua nhap la :\n");
	for (int i=1;i<=n;i++){
		printf("%d ",*(a+i));//  ptr + i là địa chỉ của số nguyên tiếp theo trong bộ nhớ sau ptr.
		// Ngược lại, ptr - i là địa chỉ của số nguyên trước đó trong bộ nhớ trước ptr.
	}
}
void themphantu(int *a,int &n,int vitrithem,int phantuthem){
	for (int i=n+1;i>=vitrithem+1;i--){
		*(a+i)=*(a+i-1);
		// ở đây chú ý a[i+1] <=> *(a+i-1)
	}
	n++;
	*(a+vitrithem)=phantuthem;
}
void xoaphantu(int *a,int &n,int vitrixoa){
	for (int i=vitrixoa;i<=n-1;i++){
		*(a+i)=*(a+i+1);
	}
	n--;
}
int main (){
	int n;
	do {
		printf("\nNhap so n:");
		scanf("%d",&n);
		if(n<1){
			printf("\nVui long nhap lai\n");
		}
	}while (n<1);
	int a[n];
	nhapmang(a,n);//thục chất teen của mảng chính là địa chỉ của ô nhớ dau tien trong mảng do nên nó la dia chỉ rồi nên la chỉ cần truyền mỗi chữ a
	inmang(a,n);
	int vitrithem,phantuthem,vitrixoa;
	printf("\nNhap vi tri them:");
	scanf("%d",&vitrithem);
	printf("\nNhap phan tu them :");
	scanf("%d",&phantuthem);
	printf("\nNhap vi tri xoa : ");
	scanf("%d",&vitrixoa);
	themphantu(a,n,vitrithem,phantuthem);
    xoaphantu(a,n,vitrixoa);
	inmang(a,n);
	return 0;
	// xoa chạy vòng for từ chỗ xóa trở đi 
	// them chạy vòng for từ n+1 trở về vị trí thêm +1 ==>>đây thực chất là dịch phần tử 
}
