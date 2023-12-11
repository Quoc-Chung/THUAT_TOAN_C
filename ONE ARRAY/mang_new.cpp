#include <iostream>
#include <algorithm>
using namespace std;
void nhap_mang(int a[],int n){
	for (int i=0;i<n;i++){
		cin>>a[i];
	}

}
void print(int i){
	cout<<i<<" ";
}
void in_mang(int a[],int n){
	cout<<"\nMang in ra la :"<<endl;
	for_each(a,a+n,print);
}
void in_mang_moi(int a[], int n) {
    cout << "\nMang in ra la: " << endl;
    for_each(a, a + n, [](int i){ 
	cout << i << " "; });
}
int main (){
	int n;
	cin>>n;
	int a[100];
	nhap_mang(a,n);
	//in_mang(a,n);
	in_mang_moi(a,n);
	cout<<endl;
	system("pause");
}
