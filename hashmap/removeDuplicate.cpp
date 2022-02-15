#include <iostream>
#define fst ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#include<algorithm>
#include<vector>
#include<unordered_map>

using namespace std;

vector<int> removeDup(int *a, int size){
    vector<int> output;
    unordered_map <int,bool> seen;
    for (int i = 0; i < size; i++)
    {
        if(seen.count(a[i]) > 0){
            continue;
        }
        seen[a[i]] = true;
        output.push_back(a[i]);
    }
    return output;
}

int main(){
    int a[] = {1,2,3,3,2,1,4,3,6,5,5};
    vector<int> output = removeDup(a,11);
    for (int i = 0; i < output.size(); i++)
    {
        cout<<output.at(i)<<endl;
    }
    
    
return 0;
}