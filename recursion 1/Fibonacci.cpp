#include<iostream>
#define fst ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long int 
#include<algorithm>
#include<vector>

using namespace std;

int fib(int a){
    if (a==0)
    {
        return 0;
    }
    if(a==1){
        return 1;
    }
    int smalloutput1 = fib(a-1);
    int smalloutput2= fib(a-2);
    return smalloutput1+smalloutput2;
}

int main(){

    cout<<fib(3)<<endl;
    
return 0;
}