#include <iostream>
#define fst ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#include<algorithm>
#include<map>
#include<vector>
using namespace std;

int main(){
    map<string, int> ourmap;
    ourmap["abc"] = 1;
    ourmap["abc1"] = 2;
    ourmap["abc2"] = 3;
    ourmap["abc3"] = 4;
    ourmap["abc4"] = 5;
    ourmap["abc5"] = 6;

    map<string, int>::iterator it = ourmap.begin();
    while (it != ourmap.end())
    {
        cout<<"key: "<< it->first <<"  value: "<<it->second<<endl;
        it++;
    }

    map<string, int>::iterator it2 = ourmap.find("abc");
    ourmap.erase(it2);

    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    vector<int>::iterator it1 = v.begin();
    while(it1 != v.end()){
        cout<<*it1<<endl;
        it1++;
    }

    
return 0;
}