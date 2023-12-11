#include <stdio.h>
#include <math.h>
// quy ước tại 1 là số nguyên tố ,tại o thì sẽ không là số nguyên tố
int prime[1000001];

void sang_nguyen_to(int n){
	// coi cả mảng đều là số 1 
	for (int i=0;i<1000000;i++){
		prime[i]=1;
	}
	prime[0]=prime[1]=0;// loại hai số 0 và số 1
	// tìm ra các số nguyên tố 
	for (int i=2;i<=sqrt(1000001);i++){
		if(prime[i]==1){
			// duyệt và loại các bội của số nguyên tố
			for (int j=i*i;j<=1000000;j+=i){
				prime[j]=0;
			}
		}
	}
	// in ra các sô nguyên tố 
	for (int i=0;i<=n;i++){
			if(prime[i]==1){
			printf("%d ",i);
		}
	}
}
// in ra các só nguyên tố trong đoạn
void sang_nguyen_to_doan(int a,int b){
	int nguyen_to[b-a+1];
	// gán tất cả các số nguyên tố trong đoạn về giá trị 1
	for (int i=0;i<b-a+1;i++){
		nguyen_to[i]=1;
	}
	if(a<=0){
		nguyen_to[a]=nguyen_to[a+1]=0;
	}
	else if(a>=2){
		for (int i=a;i<=sqrt(b-a+1);i++){
	    if(nguyen_to[i]==1){
	    	for (int j=i*i;j<=b-a+1;j+=i){
	    		nguyen_to[j]=0;
			}
		}	
	}
	// duyệt tìm bội các số nguyên tố và loại 
	for (int i=a;i<=b;i++){
		if(nguyen_to[i]==1){
			printf("%d ",i);
		}
	}
}
}
int main (){
//	int n;
//	scanf("%d",&n);
//	sang_nguyen_to(n);
   int a,b;
   scanf("%d%d",&a,&b);
   sang_nguyen_to_doan(a,b);
	return 0;
}