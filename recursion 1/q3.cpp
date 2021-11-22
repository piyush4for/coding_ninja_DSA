#include<iostream>
#define fst ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long int 
#include<algorithm>
#include<vector>

using namespace std;

int num(int n,int count){
    if(n<=0) return count;
    count++;
    return num(n/10,count);
}

int main(){

    int n,count=0;
    cin>>n;
    cout<<num(n,count);
    
return 0;
}