//its mean difference in postion of element while sorting should be not greater than k-1 that means indexes
//time complexity is O(n)
#include <iostream>
#define fst ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#include<algorithm>
#include<queue>

using namespace std;

void kSortedArray(int *a,int k,int n){

    priority_queue<int> p;
    //put first 3 elements to p
    for (int i = 0; i < k; i++)
    {
        p.push(a[i]);
    }
    //remove 1 and push 1 to get max at top of p;
    int j=0;
    for (int i = k; i < n; i++)
    {
        a[j] = p.top();
        p.pop();
        p.push(a[i]);
        j++;    
    }
    //remaining k elements were add here
    while (p.empty() != 1){
        a[j++] = p.top();
        p.pop();
    }
    
}

int main(){
    int a[]={12,15,6,7,9};
    kSortedArray(a,5,3);
    for(auto var : a)
    {
        cout<<var<<endl;
    }
return 0;
}