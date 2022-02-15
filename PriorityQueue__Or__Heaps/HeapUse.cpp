#include "PriorityQueue.h"
#include <iostream>
#define fst ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#include<algorithm>

using namespace std;

int main(){
    PriorityQueue p;

    p.insert(100);
    p.insert(10);
    p.insert(15);
    p.insert(4);
    p.insert(17);
    p.insert(21);
    p.insert(67);

    cout<<p.getSize()<<endl;
    cout<<p.getMin()<<endl;

    while (!p.isEmpty())
    {
        cout<<p.removeMin()<<" ";
    }
    
    
return 0;
}