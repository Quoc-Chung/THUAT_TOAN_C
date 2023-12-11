//Nhập vào số nguyên dương n
//Với mỗi số i từ 1 tới n:
//    Nếu i lẻ thì xuất ra số i
//    Nếu i chẵn thì xuất ra kí tự 'L'
//    Nếu i chia hết cho 4 thì xuất ra kí tự 'T'
//    Nếu i chia hết cho 8 thì xuất ra kí tự 'O'
//    Nếu i chia hết cho 16 thì xuất ra kí tự 'L'
//    Xuống dòng
//Thoát chương trình.
#include<stdio.h>
#include<math.h>
int  main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		if(i%2!=0){
			printf("\n%d",i);
		}
		else if(i%2==0){
			printf("\nL");	
		}
	else 	if(i%4==0 ){
			printf("T");
		}
	else 	if(i%8==0){
			printf("O");
		   }
	else	if(i%16==0){
			printf("L");
		}
	}
}

//1
//L
//3
//T
//5
//L
//7
//O
//9
//L
//11
//T
//13
//L
//15
//O
//17
//
//1
//L
//3
//LT
//5
//L
//7
//LTO
//9 
//L 
//11
//LT 
//13
//L
//15
//LTOL 
//17
//
//
//
//











