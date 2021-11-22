#include <bits/stdc++.h>
#define fst ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#include<algorithm>
#include<stack>
using namespace std;

bool BalancedParenthesis(string str){
    stack<int> s;
    char x;
    for (int i = 0; i < str.length(); i++)
    {
        if(str[i]=='(' || str[i]=='{' || str[i]=='['){
            s.push(str[i]);
            continue;
        }
        if(s.empty()) return false;
        switch (str[i])
        {
        case ')':
            x=s.top();
            s.pop();
            if(x=='{' || x=='[') return false;    
            break;
        case ']':
            x=s.top();
            s.pop();
            if(x=='{' || x=='(') return false;    
            break;
        case '}':
            x=s.top();
            s.pop();
            if(x=='(' || x=='[') return false;    
            break;
        
        }
    }
    return (s.empty());
}

int main(){
    string str;
    cin>>str;
    if(BalancedParenthesis(str)) 
    {
        cout<<"balanced";
    }
    else cout<<"not balanced";
   
return 0;
}