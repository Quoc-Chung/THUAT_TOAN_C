#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
// in ra chieu dai cua xau

// so sanh hai xau xem hai xau co giong nhau hay bang nhau khong'
// dao nguoc xau lai 
int  minhaiso(int a,int b){
     int  min=(a<b)?a:b;
    return min;
}
void mauchotbai(){
    printf("A -> Z la 65 -90");
    printf("a -> z la 97 -122");
    printf("0 -> 9 la 48 -57");
    printf("Hoa nho hon thuong 32 don vi .");
}
// kiem tra ki tu co phai in thuong khong
int is_lower(char c){
    if(c>='a' && c>='z'){
        return 1;
    }
    return 0;
}
// kiem tra ki tu co phai in hoa khong 
int is_upper(char c){
    if(c>='A' && c>='Z'){
     return 1;
    }
    return 0;
}
// kiem tra ki tu co phai ki tu chu cai khong
int is_alpha(char c){
  if ((c>='a' && c<='z') || (c>='A' && c<='Z')){
    //kiem tra la ki tu thì them dieu kien so 
     return 1;
  }   
  return 0;
}
// in ra ki tu thuong 
char to_lower(char c){
    if(c>='a' && c<='z'){
        c-=32;// voi in hoa thi +them 32
    }
    return c;
}
//so sanh sự giống và khác nhau giua hai xau
//strcmp(str1, str2)	> 0	 str1 > str2
//strcmp(str1, str2)	= 0	 str1 = str2
//strcmp(str1, str2)	< 0	 str1 < str2
int strcmp(char c[],char d[]){
  int n1=strlen(c);
  int n2=strlen (d);
  for (int i=1;i<= minhaiso(n1,n2);i++){
    if(c[i]!=d[i]){
        if(c[i]>d[i]){
           return 1;//tuc c > d
        }
        else {
            return -1;// tuc la c < d
        }
    }
    if(n1==n2){
        return 0;
    }
  }
}
// dao nguoc xau
char *reverse(char c[]){
    strrev(c);// chi can mot ham duy nhat la du 
      return c;
}
// v
int main (){
    char a[10]="123456789";
    printf("Xau dao nguoc cua a la %s",reverse(a));
    return 0;
}

