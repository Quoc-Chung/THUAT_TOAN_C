#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
void chu_cai_rieng_biet(char c[]) {
    int mark_alpha[128] = {0}; // sử dụng mảng 128 phần tử để đếm số lần xuất hiện của các kí tự
    
    for (int i = 0; i < strlen(c); i++) {
        if (isalpha(c[i])) {
            mark_alpha[tolower(c[i])]++; // tăng biến đếm cho kí tự tương ứng
        }
    }
    
    int dem = 0;
    for (int i = 0; i < 128; i++) {
        if (mark_alpha[i] == 1) {
            dem++;
        }
    }
    
    printf("%d", dem);
}
 int mark_alpha[256]= {0};
 void chu_cai_rieng_biet1(char c[]){
     int dem=0;
     for (int i=0;i<strlen(c);i++){
         if(isalpha(c[i])){
             mark_alpha[c[i]]++;
         }   
     }
     for (int i=0;i<128;i++){
         if(mark_alpha[i]==1){
            dem++;
         }
     }
     printf("%d",dem);
 }
int main (){
	char c[100];
	gets(c);
	chu_cai_rieng_biet1(c);
	return 0;
}