#include<iostream>
#define fst ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long int 
#include<algorithm>
#include<vector>

using namespace std;

int powe(int x,int n){
    if(n==0){
        return 1;
    }
    int output=powe(x,n-1);
    return x*output;
}

int main(){

    int x,n;
    x=2;
    n=5;
    cout<<powe(x,n);
    
return 0;
}