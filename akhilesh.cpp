#include <bits/stdc++.h>
#define fst ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#include<algorithm>

using namespace std;

int length(char ak[]){
    if(*ak == '\0') return 0;
    else return (1+length(ak+1));
}

int Blength(char *str,int length)
{
    if(*str!='\0')
    {
        length++;
        Blength(++str,length);
    }
    else
    {
        return length;
    }
}

int main(){
    char ak[]="akhileshWantAnswer";
    cout<<length(ak);
    cout<<Blength(ak,0);
    
return 0;
}