#include <bits/stdc++.h>
using namespace std;

void star(char str[],int index=0){
    
    if(str[index]=='\0') return ;
    
    star(str,index+1);
    
    if(str[index] == str[index+1]){
        str[strlen(str)+1] = '\0';
        for (int i = strlen(str); i >=index+1; i--)
        {
            str[i+1]=str[i];
        }
        str[index+1]='*';
    }
}
int main()
{
    char str[]="aaaa";
    int size=strlen(str);
    star(str);
    cout<<str;
    return 0;
}