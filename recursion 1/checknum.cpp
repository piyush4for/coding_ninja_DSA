#include<iostream>
#define fst ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long int 
#include<algorithm>
#include<vector>

using namespace std;

bool checker(int n,int ar[],int x){
    if(n<0) return false;
    if(ar[n-1]==x && n>0){
        return true;
    }
    return checker(n-1,ar,x);
}

int main(){

    int n=3;
    int ar[]={9,8,10};
    int x=9;
    cout<<checker(n,ar,x);
    
return 0;
}