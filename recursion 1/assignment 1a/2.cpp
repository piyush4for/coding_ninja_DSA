#include<iostream>
#define fst ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long int 
#include<algorithm>
#include<math.h>

using namespace std;

int zeroes(int a,int count){

    if(log10(a) <1) return count;
    if( a % 10 == 0){
        count++;
    }
    return zeroes(a/10,count);

}

int main(){

int a=102040,count=0;
cout<<zeroes(a,count);    

return 0;
}