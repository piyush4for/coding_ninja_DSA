#include<iostream>
#define fst ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long int 
#include<algorithm>
#include<math.h>

using namespace std;

double gsum(int k){
    if(k<=0){
        return 1;
    }
    double smalloutput = gsum(k-1);
    return (smalloutput+(1/pow(2,k)));
}

int main(){

    double k=3;
    cout<<gsum(k);
    
return 0;
}