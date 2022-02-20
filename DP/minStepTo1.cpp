#include <iostream>
#define fst ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#include<algorithm>
#include<climits> 
using namespace std;

//3^n time
int minStep1(int n){
    if(n<=1){
        return 0;
    }
    int x = minStep1(n-1);
    int y=INT_MAX,z=INT_MAX;
    if(n%2 == 0){
        y = minStep1(n/2);
    }
    if(n%3==0){
        z= minStep1(n/3);
    }

    return 1+min(x,min(y,z));
}

//memoization
int minStep2Helper(int n, int *array){
    if(n<=1){
        return 0;
    }
    if(array[n] != -1){
        return array[n];
    }

    int x = minStep2Helper(n-1,array);
    int y=INT_MAX,z=INT_MAX;
    if(n%2 == 0){
        y = minStep2Helper(n/2,array);
    }
    if(n%3==0){
        z= minStep2Helper(n/3,array);
    }

    array[n] = min(x,min(y,z))+1;
    return array[n];
}
int minStep2(int n){
    int *array = new int[n+1];
    for (int i = 0; i < n+1; i++)
    {
        array[i] = -1;
    }
    return minStep2Helper(n,array);
}

//dp
int minStep3(int n){
    int *ans = new int[n+1];
    ans[1] = 0, ans[2]=ans[3]=1;
    for (int i = 4; i <= n; i++)
    {
        int b=INT_MAX,c=INT_MAX;
        if(i%2==0){
            b = ans[i/2];
        }
        if(i%3 == 0){
            c = ans[i/3];
        }
        ans[i] = 1+min(ans[i-1],min(b,c));
    }
    return ans[n];

}

int main(){
    int n;
    cin>>n;
    cout<<minStep3(n);
    
return 0;
}