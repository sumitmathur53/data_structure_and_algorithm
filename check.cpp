#include<bits/stdc++.h>
using namespace std;

// map is an assosiative array
int main(){

    map<int,int> order;
    map<string,int> marks;

    marks["sumit"] = 98;
    marks["jack"] = 59;
    marks["jai"] = 10;

    map<string,int> :: iterator it;

    for(it = marks.begin(); it!=marks.end();it++){
        cout<<(*it).first<<" "<<(*it).second;
        cout<<endl;
    }   

    for(auto it : marks){
        cout<<(it).first<<" "<<(it).second;
        cout<<endl;
    }

   

}