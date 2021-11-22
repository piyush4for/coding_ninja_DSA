//multiplication recursion
#include<iostream>
#define fst ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long int 
#include<algorithm>
#include<vector>

using namespace std;

int multiply(int a,int b){
    if (b<1)
    {
        return 0;
    }
    int smalloutput= multiply(a,b-1);
    return a+smalloutput;
}

int main(){

    int a=5,b=3;
    cout<<multiply(a,b);
    
return 0;
}