#include<iostream>
#include<map>
// #include<iterator>
using namespace std;

int main(){
    map<string,string> set;
    map<string,string> reverse_set;

    set.insert({"Chennai","Bangalore"});
    set.insert({"Bombay", "Delhi"});
    set.insert({"Goa","Chennai"});
    set.insert({"Delhi", "Goa"});

    for(auto itr=set.begin();itr!=set.end();itr++){  //Creating reverse set
        string a=itr->first;
        string b=itr->second;
        reverse_set.insert({b,a});
    }
    string starting;
    for(auto itr=set.begin();itr!=set.end();itr++){  //find Starting point
            string a=itr->first;
            
            if(reverse_set.find(itr->first)==reverse_set.end()){
                starting=itr->first;
                break;
            }
        }
    auto itr=set.find(starting);
    cout<<starting;
    while(itr!=set.end()){
        cout<<"->"<<itr->second;
        starting=itr->second;
        itr=set.find(starting);
    }
    // cout<<starting;

    return 0;
}