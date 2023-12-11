#include<bits/stdc++.h>
using namespace std;
int main(){
	// khai báo vector voi list 
	// vector <Kieu du lieu > TenVector;
	// list<Kieu Du Lieu> Ten List;
	
	vector<int> vt;
	list<int> ls;
	// Thêm mot phan tu vao cuou list hoc la vector 
	// vt.push_back(PhanTu);
	// ls.push_back(PhanTu);
	ls.push_back(100);
    ls.push_back(200);	
	ls.push_back(300);
	ls.push_back(400);

        cout <<"\nList ban dau :"<<endl;
    	for (list<int> :: iterator it = ls.begin() ; it != ls.end(); it++){
	       cout <<(*it)<< " ";
	    }
    int PhanTuXoa;
    cout<<"\nNhap phan tu xoa:";
	cin >> PhanTuXoa;
	     for (list<int> :: iterator it = ls.begin() ; it != ls.end(); it++){
	     	if(*it == PhanTuXoa){
	     		it = ls.erase(it);
	     	}
	    }
		cout <<"\n List sau khi xoa :"<<endl;
		for (list<int> :: iterator it = ls.begin() ; it != ls.begin(); it++){
	       cout << *it << " ";
	    }
	            
}
