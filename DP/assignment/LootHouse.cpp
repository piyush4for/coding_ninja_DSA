#include <iostream>
#define fst ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#include<algorithm>

using namespace std;

//recursive
int MaxSum(int i,int numOfHouse,int *amountOfMoney){
    if(i>=numOfHouse) return 0;
    int AtIAndIplus2 = amountOfMoney[i] + MaxSum(i+2,numOfHouse,amountOfMoney);
    int ATIAndIplus1 = MaxSum(i+1,numOfHouse,amountOfMoney);
    return max(ATIAndIplus1,AtIAndIplus2);
}

int main(){
    int numOfHouse=0;
    cin>>numOfHouse;
    int amountOfMoney[numOfHouse];
    for (int i = 0; i < numOfHouse; i++)
    {   
        cin>>amountOfMoney[i];
    }
    cout<<MaxSum(0,numOfHouse,amountOfMoney);
    
return 0;
}