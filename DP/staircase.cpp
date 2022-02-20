#include <iostream>
#define fst ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#include<algorithm>

using namespace std;

//dp
int TotalHops3(int n){
    int arr[n+1];
    arr[0]=1;
    arr[1]=1;
    arr[2]=2;
    for (int i = 3; i < n+1; i++)
    {
        arr[i] = arr[i-1]+arr[i-2]+arr[i-3];
    }
    return arr[n];
}

//memoization
int TotalHops2(int n,int *arr){
    if(n==0) return 1;
    if(n == 1 || n == 2) return n;

    if(arr[n] != -1) return arr[n];

    arr[n] = TotalHops2(n-1,arr)+TotalHops2(n-2,arr)+TotalHops2(n-3,arr);
    return arr[n];
}

int TotalHops2Helper(int n){
    int *arr = new int[n+1];
    for (int i = 0; i < n+1; i++)
    {
        arr[i] = -1;
    }
    return TotalHops2(n,arr);
}


//recursive
int TotalHops(int n){
    if(n==0) return 1;
    if(n == 1 || n == 2) return n;
    return TotalHops(n-1)+TotalHops(n-2)+TotalHops(n-3);
}

int main(){
    int n;
    cin>>n;
    cout<<TotalHops3(n);
    
return 0;
}