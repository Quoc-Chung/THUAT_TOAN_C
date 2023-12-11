#include <stdio.h>
#include <math.h>
#include <string.h>
// pos:Vi trí kí tự được đánh dấu để xóa từ kí tự đó  
//count :So ki tu được xóa từ kí tự đó  
char *strndel(char *c, int  pos, int  count){
    // truyền con trỏ để có thể thay đổi được giá trị minh vua lam thay doi
    int  len = strlen(c);// do dai xau 
    if (pos >= len) return c;// dieu kien vi pham hàm xoa ki tu trong xau
    if (pos + count > len) count = len - pos;// xua lai so ki tu xoa de phu hop voi bai yeu cau 
    for (int  k = 0; k <= len - pos - count; k++)
        c[pos+k] = c[pos +count + k];
    return c;
}
int  main(){
    char c[] = "Tu Quoc Chung";
     int  pos = 4, count =4;
     int  pos2= 1, count2 = 2;
    printf("\nXau nguon:%s\n", c);
    printf("\nSau khi xoa %d ky tu, tu vi tri thu %d (dem tu 0)\n",count,pos);
    strndel(c,pos,count);
    strndel(c,pos2,count2);
    printf("Ten viet tat la:%s",c);
}