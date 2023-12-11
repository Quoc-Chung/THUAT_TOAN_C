#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
using boost::multiprecision::cpp_int;

cpp_int giai_thua(int n) {
    cpp_int res = 1;
    for (int i = 2; i <= n; i++) {
        res *= i;
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    cpp_int gt = giai_thua(n);
    string s = gt.str();
    int dem = 0;
    for (int i = s.length()-1; i >= 0; i--) {
        if (s[i] != '0') {
            break;
        }
        if (s[i] == '0') {
            dem++;
        }
    }
    cout << dem << endl;
    return 0;
}
