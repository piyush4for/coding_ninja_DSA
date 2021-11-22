#include<iostream>
using namespace std;
//it help in function calling as no need for chagning or using int function
int main(){
	int i=10;
	int& j=i;
	int k=11;

	j=k;
	cout<<i<<endl;
}
