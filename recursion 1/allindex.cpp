#include<iostream>
#define fst ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long int 
#include<algorithm>
#include<vector>

using namespace std;

void allindex(int n,int ar[],int x){
    if(n<0){
        return ;
    }
    if(ar[n-1]==x){
        cout<<n-1<<"\t";
    }
    allindex(n-1,ar,x);
}

int main(){

    int n=5;
    int ar[]={9,8,10,8,8};
    int x=8;
    allindex(n,ar,x);
    
return 0;
}