#include <bits/stdc++.h>
#define fst ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#include<algorithm>

using namespace std;

bool pow2(int num){
    for (int i = 0; i < 30; i++)
    {
        if(pow(2,i)==num) return true;
    }
    return false;
}
int main(){
    int num=258;
    cin>>num;
    cout<<pow2(num);

return 0;
}