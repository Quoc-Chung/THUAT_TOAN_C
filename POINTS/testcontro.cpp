#include <stdio.h>
#include<math.h>
// neu khong truyen con tro cho ham doi cho a va b
void swap(int m,int n){
	int tam=m;m=n;n=tam;
}
void swap2(int *x,int *y){
	int tam =*x;*x =*y;*y=tam;
}
void inmang(int *a,int n){
	for (int i=1;i<=n;i++){
		printf("%d",a[i]);
	}
}
int main (){
	int a=10;
	int b=20;
	int n=10;
	int arr[n]={1,2,3,4,5,6,7,8,9,10};
	swap(a,b);// ta nhan thay ham nay cha co tac dung deo gi tuc la no chi thuc hien hoan vi trong ham ma 
	// khong the mang cai hoan vi ay di su dung tuy tien cho cac bien da duoc khai bao san trong ham 
	//--->> cac o day la ta truyen dia chi cua bien do di vao trong ham ,no se thuc hien hoan vi gia tri cua dia chi ma ta truyen vao
	// la co the doi cho duoc (luc goi ham phai goi dia chi ,rieng mang thif khong vi thuc chat no cung la mot con tro)
	// _>>>ham swap2
	printf("Khong truyen con tro :\n");
	printf("Gia tri a la :%d\nGia tri b la:%d",a,b);// gia tri khong doi duoc
	printf("\nLuc ta truyen con tro:\n ");
	swap2(&a,&b);
	printf("Gia tri a la :%d\nGia tri b la:%d",a,b);
	// doi voi mang cung tuong tu chi khac luc truyen vao ham thi ta truyen luon mang chu khong can trruyen dia chi 
	inmang(arr,n);
	// hieu don gian la khong can truyen dia chia the la duoc
	
}