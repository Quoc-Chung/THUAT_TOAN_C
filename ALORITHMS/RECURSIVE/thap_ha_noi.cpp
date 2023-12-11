#include <stdio.h>
#include <math.h>
char c[3]={'A','B','C'};
void tower(int n,int dau,int cuoi,int trunggian){
	if(n==1){
	printf("\nChuyen %d dia tu cot %c sang %c",n,c[dau],c[cuoi]);
	}
	else {
		tower(n-1,dau,trunggian,cuoi);// vì cột cuối lúc này không còn là dích chuyển đĩa đến nữa mà trở 
		// thành cột trung gian giúp chuyển (n-1) đĩa (tức 2 đĩa sang cột trung gian ) mà không bị mất đi 
		// đặc tính đĩa lớn xếp dưới đĩa bé
		printf("\nChuyen %d dia tu cot %c sang %c",n-1,c[dau],c[cuoi]);
		tower(n-1,trunggian,dau,cuoi);
		//cột 1 giờ lại đóng vai trò trung gian nên cột trung gian và cột dau se thay the cho nhau
		// ta sẽ chuyển hết đĩa từ cột trung gian sang cột đàu và cứ lặp đi lặp lại như vậy 
	}
}
int main (){
	int n;
	printf("\nNhap so dia :");
	scanf("%d",&n);
	int dau=0,cuoi=2,trunggian=1;
	tower(n,dau,cuoi,trunggian);// maaarntg bắt đầu từ 0 nên ta phải nắt đầu từ 0;
	return 0;
}