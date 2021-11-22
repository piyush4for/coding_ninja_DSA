#include <bits/stdc++.h>
using namespace std;
class student {
    int age;
    char *name;
    
    public:
    student(int age,char *name){
        this ->age = age;
        //shallow copy rather thsn copying array it copy address
   //     this ->name = name;
   //deep copy
           this ->name = new char[strlen(name)+1];
           strcpy(this->name,name); 
    }

    void display(){ 
        cout<<name<<" "<<age<<endl;
        }
};