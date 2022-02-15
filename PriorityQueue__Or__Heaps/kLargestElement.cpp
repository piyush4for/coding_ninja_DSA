//if asked kLargestElements then use minPriorityQueue(to create just type priority_queue<int, vector<int>, greater<int>> p)
#include <bits/stdc++.h>
#define fst ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#include<algorithm>

using namespace std;

vector<int> kLargestElement(int *a,int k,int n){
    priority_queue <int, vector<int>, greater<int> > p;
    vector<int> ans;
    for (int i = 0; i < k; i++)
    {
        p.push(a[i]);
    }
    for (int i = k; i < n; i++)
    {
        if(p.top() < a[i]){
            p.pop();
            p.push(a[i]);
        }
    }
    for (int i = 0; i < k; i++)
    {
        ans.push_back(p.top());
        p.pop();
    }
    return ans;
    
}

int main(){
    int a[]={2, 12, 9, 16, 10, 5, 3, 20, 25, 11, 1, 8, 6};
    vector<int> ans = kLargestElement(a,4,13);
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans.at(i)<<endl;
    }
    
        
return 0;
}