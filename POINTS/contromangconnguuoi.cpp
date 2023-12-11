#include <stdio.h>
#include <math.h>
#include <string.h>
struct connguoi{
	connguoi(char ten_bo, int t,float v1,float ccao){
	 ten = ten_bo;
     tuoi=t;	
	 vong_mot=v1;
	 chieucao=ccao;            
	}
	char ten;
	int tuoi;
	float vong_mot;
	float chieucao;
};
// không nên cộng trừ trên địa chỉ sẽ gây nên rất nhiều rủi do 
int main (){
connguoi hoiphunu[3]={
connguoi('Thao',22,95,1.70),
connguoi('Thuong',30,86,1.72),
connguoi('Hoa',20,88,1.78)
};
for (int i=1;i<=3;i++){
	printf("\n%s",hoiphunu[i].ten);
}
return 0;
}