#include <iostream>
#define fst ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#include<algorithm>
#include<vector>
#include<unordered_map>
using namespace std;

vector<int> ans(int s1,int *a1, int s2, int *a2){
    //mine answer
    unordered_map<int,bool> map1;
    unordered_map<int,bool> map2;
    vector<int> v;
    for (int i = 0; i < s1; i++)
    {
        if(map1[a1[i]] > 0 ) continue;
        map1[a1[i]] = 1;
    }
    for (int i = 0; i < s2; i++)
    {
         if(map2[a2[i]] > 0 ) continue;
        map2[a2[i]] = 1;
    }
    for (int i = 0; i < s2; i++)
    {
        if(map1[a2[i]] > 0){
            v.push_back(a2[i]);
        }
    }
    return v;
}

//another way
void intersection(int input1[], int input2[], int size1, int size2) {
    unordered_map<int,int> m1 ;
  
    
    for(int i=0 ;i<size1 ;i++)
         m1[input1[i]]++;
    
    for(int i=0 ;i<size2 ;i++)
    {
        if(m1[input2[i]]>0)
        {
            cout<<input2[i]<<endl;
            m1[input2[i]]--;  //reduce its occurence by 1;
        }
            
    }
    
}

int main(){
    int T;
    cin>>T;
    int s1=0,a1[s1],s2=0,a2[s2];
    
    while(T--){
        cin>>s1;
        for (int i = 0; i < s1; i++)
        {
            cin>>a1[i];
        }
        cin>>s2;
        for (int i = 0; i < s2; i++)
        {
            cin>>a2[i];
        }
        
    }
    // int s1=6,s2=4,a1[]={2,6,8,5,4,3},a2[]={2,3,4,7};
    vector<int> v = ans(s1,a1,s2,a2);
    // intersection(a1,a2,s1,s2);

    for (int i = 0; i < v.size(); i++)
    {
        cout<<v.at(i)<<" ";
    }
    

return 0;
}