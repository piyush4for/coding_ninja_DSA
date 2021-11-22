#include<iostream>
using namespace std;
int main(){
	int a=7;
	int * c = &a;
	c++;
	cout<<a<<"  "<<*c<<endl;
return 0;
}

