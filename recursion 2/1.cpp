//replace character recusively
#include <bits/stdc++.h>
#define fst ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long int 
#include<algorithm>

using namespace std;

void replaceChar(char str[],char c1,char c2){
    if(str[0]==c1) str[0]=c2;
    if (str[1]=='\0') return ;
    replaceChar(str+1,c1,c2);
}

int main(){

    char str[100]="abaca";
    char c1='a',c2='x';
    replaceChar(str,c1,c2);
    cout<<str;
return 0;
}