
// cong thuc : strtok(chuỗi cần tách,chỗ cần đánh dấu " ")
#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(){
	char c[1000];
	gets(c);
  char *p = strtok(c," ");//Hàm strtok() trar về vị trí đầu chuỗi phân tách dưới dạng con trỏ 
while (p!=NULL){
	printf("%s\n",p);
	p=strtok(NULL," ");
}
}