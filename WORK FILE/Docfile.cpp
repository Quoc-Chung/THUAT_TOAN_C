#include <stdio.h>
#include <math.h>
#include <stdlib.h>
//minh lưu gia tri o file nao thi doc gia tri o dia chi file do
int main(){
// 1 .tạo một con trỏ  để tí trỏ đến địa chỉ của hàm mở file 
	FILE *f;
// cho con trỏ trỏ đến địa chỉ của  file ở chế độ nhập là "r" tức read
	f = fopen("C:\\Users\\Admin\\Documents\\FILE GHI\\Testdau.txt","r");
	if(f==NULL){
		printf("\ Loi tao hoac mo file!");
		exit(1);
	}
	//3 Doc du lieu
	int n;
	// nhap du liệu vào trong tệp 
	fscanf(f,"%d", &n);//vì là scanf thì vẫn phải truyền địa chỉ vào 
	printf("\nGia tri cua n: %d", n);
	//4 Dong file
	fclose(f);
}
// append:nối vào 