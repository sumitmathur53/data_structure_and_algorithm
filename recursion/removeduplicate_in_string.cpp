#include<bits/stdc++.h>
using namespace std;

string removedup(string s){
    if(s.length()==0){
        return "";
    }

    char sh = s[0];
    string rest = removedup(s.substr(1));

    if(sh == rest[0]){
        return rest;
    }
    else{
        return (sh + rest);
    }
}

int main(){
    cout<<removedup("asdnjjknnslddds")<<endl;
}