#include <stdio.h>
#include <math.h>
#include <string.h>
char s[10000],x[10000];
int tinh()
{
    int len=strlen(s);
    if (len%2!=0)
        return (s[len/2]-48);
    return (s[len/2 - 1]-48)*10 + (s[len/2]-48);
}
int  main()
{
    int n,gt=-1;
    int i,j;
  printf("Nhap n:");
  scanf("%d",&n);
    for ( i=1;i<=n;i++){
        scanf("%s",&s);
        if (tinh()>=gt)
        {
            gt=tinh();
            for ( j=0; j<strlen(s); j++)
                x[j]=s[j];
            x[j]='\0';
        }
    }
    printf("%s",x);
	    return 0;
}