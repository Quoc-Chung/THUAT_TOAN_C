#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
void kiem_tra_chuoi_so(char c[]){
	int flag=0;
	for(int i=0;i<strlen(c);i++){
		if(!isdigit(c[i])&&!isspace(c[i])){
			flag++;
			break;
		}
	}
	if(flag==0){
		printf("\nChuoi nay la chuoi so.");
	}
	else {
		printf("\nChuoi khong la chuoi so.");
	}
}
int main(){
	char c[100];
	gets(c);
	kiem_tra_chuoi_so(c);
	return 0;
	
}