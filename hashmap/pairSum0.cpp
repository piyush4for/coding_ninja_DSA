//maybe the answer is not correct for some test case
//map  and set are same but just set only contain key not value and both are contrcuted from BST

#include <iostream>
#define fst ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#include<algorithm>
#include<unordered_map>

using namespace std;

int pairZero(int *a,int size){
    int count=0;
    unordered_map<int,int> map;
    for (int i = 0; i < size; i++)
    {
        map[a[i]]++;
        
    }
    for (int i = 0; i < size; i++)
    {
        if(map[-a[i]]){
            count++;
            map[a[i]]--;
        }

    }
        return count;
}

int main(){
    // int a[]={2,1,-2,2,3};
    int size=0;
    cin>>size;
    int ar[size];
    for (int i = 0; i < size; i++)
    {
        cin>>ar[i];
    }
    cout<<pairZero(ar,size);
    
return 0;
}