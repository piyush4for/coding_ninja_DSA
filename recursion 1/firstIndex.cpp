#include<iostream>
#define fst ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long int 
#include<algorithm>
#include<vector>

using namespace std;

int findex(int index,int n,int ar[],int x){
    if(n<0){
        return -1;
    }
    if(ar[index]==x){
        return index;
    }
    return findex(index+1,n,ar,x);
}

int main(){
    int n=4;
    int ar[]={9,18,8,8};
    int index=0;
    int x=8;
    cout<<findex(index,n,ar,x);
    
return 0;
}