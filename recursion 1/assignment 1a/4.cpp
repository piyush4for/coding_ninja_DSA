#include<iostream>
#define fst ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long int 
#include<algorithm>
#include<string.h>

using namespace std;

bool Palrev(char str[],int i,int last){
    if(i==last) return true;
    if(str[i]!=str[last]) return false;
    if(i<last) return Palrev(str,i+1,last-1);
    return true;
}

bool isPalindrome(char str[]){
    int l = strlen(str);
    if(l == 0) return true;
    return Palrev(str,0,l-1);
}

int main(){

    char str[] ="racecar";
    if(isPalindrome(str)) cout<<"true";
    else cout<<"false";
    
return 0;
}