#include <iostream>
#include<vector>
using namespace std;

int main(){
	//dynamic allocation
	//vector<int> * vp = new vector<int>();
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	
	cout<<v[1]<<endl;

}
