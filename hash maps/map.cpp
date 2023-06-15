#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

int main(){

    unordered_map<string , int> MAP;
    // insert

    pair<string,int> p("abc" , 1);

    MAP.insert(p);
    // we can insert like array
    MAP["def"] = 2;

    cout<<MAP["abc"]<<endl;
    cout<<MAP.at("abc")<<endl;

    //cout<<MAP.at("abs")<<endl;  // this give error

    cout<<MAP["ghi"]<<endl;  // square bracket give 0 and the insert the key at 0

    // check presence

    if(MAP.count("ghi") > 0){  // it give 0 or 1 only
        cout<<"ghi is present"<<endl;
    }

    cout<<"size of map ->"<<MAP.size()<<endl;

    MAP.erase("ghi");  // it will erase the key

    if(MAP.count("ghi") > 0){  // it give 0 or 1 only
        cout<<"ghi is present"<<endl;
    }

    cout<<"size of map ->"<<MAP.size()<<endl;
}