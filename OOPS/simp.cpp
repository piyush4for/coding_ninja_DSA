#include <bits/stdc++.h>
#define fst ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#include<algorithm>
#include "simple.cpp"
using namespace std;

int main(){
    student s1;
    s1.age=2;
    cout<<s1.age<<endl;
    
    student *s2 = new student;
    getline(cin,(*s2).name);
    s2 ->age = 333;
    cout<<(*s2).name<<endl<<s2->age;
return 0;
}