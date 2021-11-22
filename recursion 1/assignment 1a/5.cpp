#include<iostream>
#define fst ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long int 
#include<algorithm>
#include<vector>

using namespace std;

int sum(int a){
    if(a == 0){
        return 0;
    }
    int smalloutput=a%10;
    return smalloutput+sum(a/10);
}

int main(){

    int num=9;
    cout<<sum(num);
    
return 0;
}