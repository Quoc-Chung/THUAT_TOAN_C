#include <stdio.h>
#include <math.h>
void input(int a[],int n){
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
}
int main(){
	int t;
	scanf("\n%d",&t);
	for(int i=1;i<=t;i++){// thay cho vong lap while (t--)vi ti ta con phai dung bien tang i
		int n;
		scanf("\n%d",&n);
		int a[n];
		input(a,n);
		int kiluc=1;// reset lai ki luc cac day con dai nhat 
		int count=0;// so luong day con 
		int dem=1;// dem xem day con dai nhat co bao nhieu so 
		int b[n];// luu chi so dau ua tung day con 
		b[0]=0,count =1;// reset lai bien count va cho chi so dayu cua b bàng 0;
		for (int i=1;i<n;i++){
			if(a[i]>a[i-1]){// a[i] so truoc  a[i]-1
		//	if(a[i+1]>a[i]){
				++dem;
			}
			else {
				dem=1;
			}
			if(kiluc<dem){
				kiluc=dem;
				// cap nhat chi so day con 
				b[0]=i-kiluc+1;
				count =1;// khi do chi co mot day con 
			}
			else if(kiluc==dem){
				b[count]=i-kiluc+1;
				++count;
			}
		}
		printf("\nTest %d:",i);
		printf("%d\n",kiluc);
		for (int i=0;i<count;i++){// duyet qua tung chi so cua mang b[i] 
		// so luong gia tri cua b[i] bang 
			for (int j=0;j<kiluc;j++){// duyet qua tung tu chi so dau den chi so cuoi cua ki luc 
			printf("%d ",a[b[i]+j]);// b[i] la chi so dau cua day con ;j la chi so tu dau den cuoi cua day con do 	
			}
			printf("\n");
		}		
	}
}