#include <iostream>
#define fst ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#include<algorithm>
#include<vector>
#include<unordered_map>

using namespace std;

int maxFrequency(int *a, int size){
    unordered_map<int, int> map;
    int m=1,k=1;
    for (int i = 0; i < size; i++)
    {
        map[a[i]]++;
        if(m < map.at(a[i])){
            m=map.at(a[i]);
            k=a[i];
        }
    }
    return k;
}

//2, 12, 2, 11, 12, 2, 1, 2, 2, 11, 12, 2, 6
int main(){
    int a[] = {3,2,4};
    cout<<maxFrequency(a,3);

    
return 0;
}