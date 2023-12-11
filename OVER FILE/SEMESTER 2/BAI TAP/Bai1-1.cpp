//
//Tệp có cấu trúc như sau: Dòng đầu chứa các số nguyên n và m (giữa n và m có ít nhất một 
//dấu cách). Dòng thứ 2 chứa các hệ số ao, a1,.... an (giữa hai hệ số có ít nhất một dấu cách). 
//Dòng thứ 3 chứa các hệ số bo, b1..., bm (giữa hai hệ số có ít nhất một dấu cách). Xây dựng 
//các hàm để thực hiện các việc sau đây:
//1. Đọc các hệ số của 2 đa thức từ tệp, có cấp phát động bộ nhớ, in đa thức ra màn hình. 
//2. Nhập d1 và d2 từ bàn phím và tính: S = P(dl) /Q(d2). 
//3. Tính hệ số của đa thức hiệu: P(x) - Q(x)
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
void LayHeSoTuFile(int a[],int b[],int &m,int &n){
	FILE *f;
	f=fopen("C:\\Users\\Admin\\Documents\\LAP TRINH\\DEV C++\\THUATTOANC\\WORK FILE\\LUU TRU\\Bai Tap\\Bai1-1.txt","r");
	if(f==NULL){
		printf("\nKhong mo duoc file de doc.");
		exit(1);
	}
	fscanf(f,"%d",&n);
	fscanf(f,"%d",&m);
	for(int i=0;i<n;i++){
		fscanf(f,"%d",&a[i]);
	}
	for(int i=0;i<m;i++){
		fscanf(f,"%d",&b[i]);
	}
	fclose(f);
}
void TinhThuong(int a[],int b[],int m,int n){
	int d1,d2;
	printf("\nNhap d1:");
	scanf("%d",&d1);
	printf("\nNhap d2:");
	scanf("%d",&d2);
	float P=0,Q=0;
	for(int i=0;i<n;i++){
		 P+=a[i]*pow(d1,i);
	}
	for(int i=0;i<m;i++){
		 Q+=b[i]*pow(d2,i);
	}
	printf("\nS=%.2f",P/Q);
}
//4 5
//5 -2 3 6
//1 -4 5 3 2    ==> hệ số  -2 3 -2 2 4
void TinhHeSo(int a[], int b[], int n, int m) {
    int do_dai = (n > m) ? m : n;
    int *c = (int*)malloc((do_dai) * sizeof(int));
    for (int i = 0; i<=do_dai;i++) {
        if (i <= n && i <= m) {
            c[i] = a[i] - b[i];      
        }
    }
    printf("\nHe so cua hieu la:\n");
    if(n>m){
    	for(int i=m;i<n;i++){
    		printf("%d ",-b[i]);
		}
	}
	else{
		for(int i=n;i<m;i++){
			printf("%d ",-a[i]);
		}
	}
    for (int i = do_dai-1; i >= 0; i--) {     
            printf("%d ", c[i]);
    }
    
    free(c);
}
int main(){
	int *a,*b,m,n;
	a=(int*)malloc (n*sizeof(int));
	b=(int*)malloc (m*sizeof(int));
	LayHeSoTuFile(a,b,n,m);
	TinhThuong(a,b,n,m);
	TinhHeSo (a,b,n,m);
	return 0;
	
}