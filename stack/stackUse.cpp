#include <bits/stdc++.h>
#define fst ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#include<algorithm>
#include "StackUsingArray.cpp"
#include "StackUsingTemplate.cpp"
#include "stackUsingLL.cpp"

using namespace std;

int main(){
    // StackUsingArray s;
    // StackUsingTemplate<char> s;
    Stack<char> s;
    s.push(100);
    s.push(101);
    s.push(102);
    s.push(103);
    s.push(104);
    
    cout<<s.top()<<endl;

    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    
    cout<<s.getSize()<<endl;
    cout<<s.isEmpty()<<endl;

 
return 0;
}