#include <bits/stdc++.h>
#define fst ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#include<algorithm>
#include "student.cpp"
using namespace std;

int main(){
    char name[]="abcd";
    student s1(20,name);
    s1.display();

    name[3]='e';
    student s2(24,name);
    s2.display();
    s1.display();

return 0;
}