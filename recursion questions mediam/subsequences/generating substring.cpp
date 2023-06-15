#include<bits/stdc++.h>
using namespace std;

void substring(string s, string ans){

    if(s.length()==0){
        cout<<ans<<endl;
        return;
    }

    char ch = s[0];
    string restString = s.substr(1);

    
    substring(restString,ans+ch);
    substring(restString,ans);


}

int main(){
    string s = "abc";
    substring(s,"");
}