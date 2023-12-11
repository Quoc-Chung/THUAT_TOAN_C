#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int a[5] = {1, 3, 5, 4, 6};
    for (int i : a) {// duyệt qua từng phần tử trong mảng với biến y lúc này là giá trị của từng phần tử trong mảng 
        cout << i << " ";
    }
    return 0;
}