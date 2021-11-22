//sum of elements 
#include<iostream>
#define fst ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long int 
#include<algorithm>
#include<vector>

using namespace std;

int sumof(int ar[],int n){
   if(n<=0){
       return 0;
   }
   return (sumof(ar,n-1)+ar[n-1]);
}

int main(){

    int n=3;
    int ar[n]={4,2,1};
    cout<<sumof(ar,n);
    
return 0;
}