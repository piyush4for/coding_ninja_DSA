#include<iostream>
#define fst ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long int 
#include<algorithm>
#include<vector>

using namespace std;

int lindex(int n,int ar[],int x){
    if(n<0){
        return -1;
    }
    if(ar[n-1]==x){
        return n-1;
    }
    return lindex(n-1,ar,x);
}

int main(){

    int n=4;
    int ar[]={9,8,10,8};
    int x=8;
    cout<<lindex(n,ar,x);
    
return 0;
}