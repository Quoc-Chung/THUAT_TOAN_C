#include <stdio.h>
#include <math.h>
void nhapmang(int a[],int n){
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
}
int main (){
 int t;
 scanf("%d",&t);
 for (int i=1;i<=t;i++){
 	//input test case 
 	int n;
 	scanf("%d",&n);
 	int a[n];
 	nhapmang(a,n);
 	// dem so day con asending 
 	int count=0;
 	// tao bien dem do dai day con 
 	int dem =1;
 	// tao bien luu ki luc cua day con khi mot mang xuat hien nhieu day con co do dai tuong tu nhau thoa man 
 	int kiluc=0;
 	// tao mang luu chi so cua cac phan tu tang 
 	int b[n];
 	// reset lai bien so day va mang luu vi tri cua day asending 
 	count =1;
 	b[0]=0;
 	// exam  phan tu asending
 	for (int i=0;i<n;i++){
 		if(a[i-1]<a[i]){
 			dem++;
		 }
		 // neu o khong tang thi reset lai bien dem=1
		 else {
		 	dem=1;
		 }
		if(kiluc<dem){
			kiluc=dem;
			// gia tri mang b bang chi so day con 
			b[0]=i-kiluc+1;
			count =1;// chi co mot day con thoa man 
		}
		else if(kiluc==dem ){
			// mang b luu gia tri cua tung vi tri dau trong day con 
			b[count]=i-kiluc+1;
			count ++;// tuc la co nhieu day con 
		}
	}
	printf("\nTest %d:\n",i);
	printf("\n",kiluc);// tuc la do dai day tang 
		for (int i=0;i<count;i++){
			for (int j=0;j<kiluc;j++){
				printf("\n%d ",a[b[i]+j]);
			}
		}
		printf("\n");
	 }
 }