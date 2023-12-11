#include <stdio.h>
#include <math.h>
#include <string.h>
int main (){
	char c[1000];
	gets(c);
	// cho con trỏ trỏ đến địa chỉ đầu tiên của mảng kí tự vừa nhập
	char *ptr=c;
	// cho con trỏ trỏ đến kí tự đầu tien của mảng hello 
	char * p= "hello";
	while (*p != '\0' && *p != '\0'){
		if(*ptr == *p){
			p++;// dich chuyển con trỏ đến địa chỉ của kí tự thứ hai trong mảng hello 
		}
		// cho dù không thấy thì sau mỗi vòng lặp cũng sẽ dịch địa chỉ của chuỗi mẹ
		ptr++;
	}
	// nếu con trỏ *p_hello có thể dịch chuyển đến cuối thì coi như chuỗi mẹ 
	if(*p =='\0'){
		printf("\nYES");
	}
	else {
		printf("\nNO");
	}
	return 0;
}