#include <iostream>
#define fst ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#include<algorithm>
#include<queue>

using namespace std;

int main(){
    priority_queue<int> pq;
    pq.push(100);
    pq.push(10);
    pq.push(15);
    pq.push(4);
    pq.push(17);
    pq.push(2);
    pq.push(6);
    pq.push(12);

    while (pq.size() !=0)
    {
        cout<<pq.top()<<endl;
        pq.pop();
    }
    
    
return 0;
}