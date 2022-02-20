#include <iostream>
#define fst ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#include<algorithm>
#include<cmath>
#include<climits>

using namespace std;

//dp
int minCount3(int n){
    if(sqrt(n) - floor(sqrt(n)) == 0) return 1;
    int dp[n+1];
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    for (int i = 4; i < n+1; i++)
    {
        dp[i] = i;
        for (int j = 1; j*j <= i; j++)
        {
            // if((j*j) > i) break;
            dp[i] = min(dp[i],1+dp[i-(j*j)]);
        }
        
    }
    return dp[n];
}

//memoization
int minCount2(int n,int *dp){
    if(sqrt(n) - floor(sqrt(n)) == 0) {
        dp[n] = 1;
        return dp[n];
    }
    if(dp[n] != -1) return dp[n];
    if(n<4) {
        dp[n] = n;
        return dp[n];
    }
    int ans=n;
    for (int i = 1; i*i <= n ; i++)
    {
        dp[n] = ans = min(ans,1+minCount2(n-(i*i),dp));
    }
    return dp[n];
}

int minCount2Helper(int n){
    int *dp = new int[n+1];
    for (int i = 0; i < n+1; i++)
    {
        dp[i]=-1;
    }
    return minCount2(n,dp);
}

//recursion
int minCount1(int n){
    if(sqrt(n) - floor(sqrt(n)) == 0) return 1;
    if(n<4) return n;
    int ans=n;
    for (int i = 1; i*i < n ; i++)
    {
        ans = min(ans,1+minCount1(n-(i*i)));
    }
    return ans;
    
}

int main(){
    int n;
    cin>>n;
    cout<<minCount3(n)<<endl;
    cout<<minCount2Helper(n);
    
return 0;
}