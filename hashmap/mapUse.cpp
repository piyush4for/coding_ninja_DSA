//normal map use log(n) time complexity while unordered map use 0(1) time as this uses hashtable
#include <iostream>
#define fst ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#include<algorithm>
#include<unordered_map>
#include<string>

using namespace std;

int main(){
    unordered_map <string, int> mapuse;
    
    //insert
    pair <string, int> p("abc",1);
    mapuse.insert(p);
    mapuse["def"] = 2;

    //find or access
    cout<<mapuse["abc"]<<endl;      
    cout<<mapuse.at("abc")<<endl;   

    // cout<<mapuse.at("ghi")<<endl;   //just show error when note found
    cout<<"size: "<<mapuse.size()<<endl;
    cout<<mapuse["ghi"]<<endl;  //create new key and putted 0 autmatically
    cout<<"size: "<<mapuse.size()<<endl;

    //check presence
    if(mapuse.count("ghi") > 0){
        cout<<"ghi is present"<<endl;
    }

    //erase
    mapuse.erase("ghi");
    cout<<"size: "<<mapuse.size()<<endl;
    if(mapuse.count("ghi") > 0){
        cout<<"ghi is present"<<endl;
    }

return 0;
}