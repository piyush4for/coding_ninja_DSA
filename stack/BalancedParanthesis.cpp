#include <bits/stdc++.h>
#define fst ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#include<algorithm>
#include<stack>
using namespace std;

bool BalancedParenthesis(string s){
    stack<int> st;
    char x;
    for (int i = 0; i < s.length(); i++)
    {
        if(s[i]=='(' || s[i]=='{' || s[i]=='['){
            st.push(s[i]);
            continue;
        }
        if(st.empty()) return false;
        switch (s[i])
        {
        case ')':
            x=st.top();
            st.pop();
            if(x=='{' || x=='[') return false;    
            break;
        case ']':
            x=st.top();
            st.pop();
            if(x=='{' || x=='(') return false;    
            break;
        case '}':
            x=st.top();
            st.pop();
            if(x=='(' || x=='[') return false;    
            break;
        
        }
    }
    return (st.empty());
}

int main(){
    string s;
    cin>>s;
    if(BalancedParenthesis(s)) 
    {
        cout<<"balanced";
    }
    else cout<<"not balanced";
   
return 0;
}