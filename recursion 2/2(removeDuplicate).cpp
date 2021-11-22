//remove duplicate
#include <bits/stdc++.h>
#define fst ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long int 
#include<algorithm>

using namespace std;

void removed(char str[]){
    if(str[0]=='\0') return;
    if(str[0]!=str[1]) removed(str+1);
    else{
        int i=1;
        for (; str[i]!='\0'; i++)
        {
            str[i-1] = str[i];
        }
        str[i-1] = str[i];
        removed(str);
    }
}

int main(){

    char str[]="xxxyyyzwwzzz";
    removed(str);
    cout<<str;
    
return 0;
}