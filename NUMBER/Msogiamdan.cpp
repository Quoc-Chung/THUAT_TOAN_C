#include<stdio.h>
#include<math.h>
 
{
    int n;
    scanf("%d",&n);
    int flag=1;
    int ChuSoCuoi = n % 10; 
    n=n/10;
    while(n > 0)
    {
        int ChuSoKeCuoi = n % 10;
        n=n/ 10;
        if (ChuSoCuoi > ChuSoKeCuoi)
        {
            flag=0;
            break;
        }
        else
        {
            ChuSoCuoi = ChuSoKeCuoi; 
        }
    }
    if(flag==1){
        printf("Day giam dan !");
    }
	else{
        printf("Day khong giam dan !");
    }
}
