#include <bits/stdc++.h>
#define fst ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long int 
#include<algorithm>

using namespace std;

int strToint(char s[],int size){
    if(size==0) return (s[size]-'0'); 

    int smalloutput1 = s[size]-'0';
    int smalloutput2 = strToint(s,size-1);
    return 10*smalloutput2+smalloutput1;
}

int main(){

    char s[] = "41651";
    int size= strlen(s);
    cout<<strToint(s,size-1);
    // cout<<(s[0]-'0');
    
return 0;
}