#include <stdio.h>
#include <math.h>
// nhap va xuat hai day so 
void nhapmang(float  a[],int n){
	for (int i=1;i<=n;i++){
		scanf("%f",&a[i]);
	}
}
void inmang (float a[],int n){
	for (int i=1;i<=n;i++){
		printf("%.2f ",a[i]);
	}
}
// dem va in ra man hinh cac so a[i] va b[j] sao cho a[i]==b[j];
void cacsothoaman(float a[],float b[],int n){
	float so1,so2;
	int vitri1,vitri2;
	int dem=0;
	for (int i=1;i<=n;i++){
	for (int j=1;j<=n;j++){
			so1=0,so2=0;
			vitri1=0,vitri2=0;
		  if(a[i]==b[j]){
		  	vitri1=i,vitri2=j;
		  	so1=a[i],so2=b[j];
				dem++;
		printf("\nCap so (a[%d],b[%d])=(%.2f,%.2f)",vitri1,vitri2,so1,so2);	
		}
	}
}
	printf("\nVay co tat ca %d cap so thoa man.",dem);
}
//tim gia tri lon nhat cua day a,kiem tra xem tat ca phan tu cua day bco lon hon gia tri nay khong 
float max(float a[],int n){
	float max=-pow(10,5);
	for (int i=1;i<=n;i++){
		if(max <a[i]){ // tuc la a[i]>max ma max lai la mot so cuc ki be 
			max=a[i];
		}
	}
	return max;
}
void kiemtra (float a[],float b[],int n){
	float max1=max(a,n);
	int flag=0;
	for (int i=1;i<=n;i++){
		if(max1>b[i]){
			flag++;
			break;
		}
	}
	if(flag==0){
		printf("\nTat ca phan tu cua day b lon hon gia tri max cua day a.");
	}
	else{
		printf("\nTon tai nhung phan tu cua day b nho hon gt max cua day a.");
	}
}
// tìm so liên tiếp ai a[i+1] mà tích của chúng chia hết cho tổng của chúng 
void truenumber(float a[],int n){
	float so1,so2;
	int flag=0;
	for (int i=1;i<n;i++){
		if(((int)a[i]*(int)a[i+1])%((int)a[i]+(int)a[i+1])==0){
			so1=(float)a[i];
			so2=(float)a[i+1];
			flag++;
			break;
		}
	}
	if(flag==0){
	printf("\nKhong co bo so nao thoa man.");
	}
	else {
	printf("\nHai so thoa man la :(%.2f,%.2f)",so1,so2);
}
}
// tìm số chẵn lớn nhất trong dãy ,số đó xuất hiện mấy lần trong dãy 
int maxchan(float a[],int n){
	int max=-pow(10,5);
	for (int i=1;i<=n;i++){
		if((int)a[i]%2==0 && max<(int)a[i]){
			max=(int)a[i];
		}
	}

	return max;	
}
void kiemtraxuathien(float a[],int n){
	int dem=0;
	int max=maxchan(a,n);
		printf("\nGia tri max chan la :%d",max);
	for (int i=1;i<=n;i++){
		if(max==a[i]){
			dem++;
		}
	}
	printf("\nGia tri max xuat hien %d lan.",dem);
}
// tim so lon nhat trong day a xem so nao trong day b lon hon gias tri max vua tim duoc
void daysolonmax(float a[],float b[],int n){
	float sothoa;
	int max=maxchan(a,n);
	printf("\nCac so thoa man la :\n");
	for (int i=1;i<=n;i++){
		sothoa=0;
		if(b[i]>max){
			sothoa=b[i];
			printf("%.2f\t",sothoa);
		}
	}
	
}
// tính và in ra màn hình những phần tử chẵn mà không chia hết cho 4 trong dãy .
void phantu(float a[],int n){
	int sothoaman;
	printf("\nCac so thoa man la :\n");
	for (int i=1;i<=n;i++){
		sothoaman=0;
		if((int)a[i]%2==0 && (int)a[i]%4!=0){
			sothoaman=(int)a[i];
			printf("\n%d",sothoaman);
		}
	}
}
//xac dinh gia tri nho nhat cua hieu cac cap so  lien tiep trong day
void minhieu(float a[],int n){
	float min=pow(10,4);
	float so1=0,so2=0;
	int vitri1,vitri2;
	for (int i=1;i<n;i++){
		float hieu=a[i]-a[i+1];
		if(min>hieu){
			min=hieu;
			so1=a[i],so2=a[i+1];
			vitri1=i,vitri2=i+1;
		}
	}
	printf("\nCap so thoa man la (a[%d],a[%d])=()")
}
 
int main (){
	int n;
	do {
		printf("Nhap n:");
		scanf("%d",&n);
		if(n<1){
			printf("\nVui long nhap lai:\n");
		}
	}while (n<1);
	float a[1000],b[1000];
	printf("\nNhap day so a:\n");
	nhapmang(a,n);
    printf("\nNhap day so b:\n");
	nhapmang(b,n);
	printf("\nDay so a la : ");
	inmang(a,n);	
	printf("\nDay so b la : ");
	inmang(b,n);
      daysolonmax(a,b,n);
//	  cacsothoaman(a,b,n);
//	  kiemtra(a,b,n);
//    truenumber(a,n);
//    maxchan(a,n);
//    kiemtraxuathien(a,n);
//    phantu(a,n);
	return 0;
}