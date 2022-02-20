#include <iostream>
#define fst ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#include<algorithm>

using namespace std;

//approach known as DP(bottom-up)   O(n)
//using iterative method to save previous result
int fibo3(int n){
    int *ans = new int[n+1];
    ans[0] = 0;
    ans[1] = 1;
    for (int i = 2; i < n; i++)
    {
        ans[i] = ans[i-1] + ans[i-2];
    }
    return ans[n];
}

//2^n time 
int fibo(int a){
    if(a<=1) return a;
    int smalloutput1 = fibo(a-1);
    int smalloutput2= fibo(a-2);
    return smalloutput1+smalloutput2;
}

//approach known as memoization(Top-Down approcah)  O(n)
//i.e, saving previous results while recursion
int fibo_2(int a){
    int *ans = new int[a+1];
    for (int i = 0; i < a; i++)
    {
        ans[i] = -1;
    }
    
    return fibo_2helper(a,ans);
}
int fibo_2helper(int n, int *ans){
    if(n<=1) return n;
    
    if(ans[n] != -1){
        return ans[n];
    }

    int smalloutput1 = fibo_2helper(n-1,ans);
    int smalloutput2 = fibo_2helper(n-2,ans);

    ans[n] = smalloutput1+smalloutput2;
    return ans[n];
}

int main(){
    int n=3;
    cout<<fibo(n)<<"  ";
    
return 0;
}