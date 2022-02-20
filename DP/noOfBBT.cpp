//no of balanced binary tree using height
#include <iostream>
#define fst ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#include<algorithm>
#include<cmath>
#include<climits>

using namespace std;

//dp
int noOfBalancedTree3(int h){
    int *dp = new int[h+1];
    dp[0]=dp[1]=1;
    int mod = pow(10,9) + 7;
    for (int i = 2; i < h+1; i++)
    {
        int x = dp[i-1];
        int y = dp[i-2];
        dp[i] = (int)((((long long)(x)*x) % mod)+((2*(long long)(x)*y) % mod));
    }
    return dp[h];

    delete [] dp;
}

//memoization
int noOfBalancedTree2(int h,int *ans){
    ans[0]=ans[1]=1;
    if(ans[h] != -1) return ans[h];

    int mod = (int) (pow(10,9))+7;
    int x =noOfBalancedTree2(h-1,ans);
    int y =noOfBalancedTree2(h-2,ans);

    int temp1 = (int)(((long long)(x)*x) % mod);
    int temp2 = (int)((2*(long long)(x)*y) % mod);
    ans[h] = (temp1+temp2) % mod;
    
    return ans[h];
}

int noOfBalancedTree2(int h){
    int *ans = new int[h+1];
    for (int i = 0; i < h+1; i++)
    {
        ans[i] = -1;
    }
    return noOfBalancedTree2(h,ans);
}

//recursion
int noOfBalancedTree(int h){
    if(h<=1) return 1;

    int mod = (int) (pow(10,9))+7;
    int x =noOfBalancedTree(h-1);
    int y =noOfBalancedTree(h-2);

    int temp1 = (int)(((long long)(x)*x) % mod);
    int temp2 = (int)((2*(long long)(x)*y) % mod);
    int ans = (temp1+temp2) % mod;

    return ans;
}

int main(){
    int h;
    cin>>h;
    cout<<noOfBalancedTree2(h)<<endl;
    cout<<noOfBalancedTree3(h);
    
return 0;
}