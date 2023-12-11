#include <stdio.h>
#include <math.h>
void truyenthambien(int *a,int *b){
	printf("\n%d",*a);
	printf("\n%d",*b);
	*a+=1;
	*b+=1;
	printf("\n%d",*a);
	printf("\n%d",*b);
}
void truyenthamtri (int a,int b){
	printf("\n%d",a);
	printf("\n%d",b);
	a+=1;
	b+=1;
	printf("\n%d",a);
	printf("\n%d",b);
}
int main (){
	int a=10;
	int b=5;
	printf("Khi chua truyen ca gia tri tham tri va tham bien:\n"); 
	printf("%d",a);
	printf("\n%d",b);
	printf("\nKhi truyen tham bien :\n");
//	truyenthambien(&a,&b);
	printf("\n%d",a);
	printf("\n%d",b);
	printf("\nKhi truyen tham tri :\n");
	truyenthamtri(a,b);
	// ta thay truyen tham tri se khong thay doi 
	
	// truyền them biến thì lúc gọi hàm cũng phải gọi địa chỉ của biến cần truyền
	// ta thay ro ràng là số a và b đã thay đổi điều này xảy ra ở trong hàm 
	//ta thay đổi giá trị con trỏ thì giá trị của địa chỉ truyền vào cũng bị thay đổi theo 
	
}