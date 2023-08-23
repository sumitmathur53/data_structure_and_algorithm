#include<bits/stdc++.h>
using namespace std;


void printAllPermutation(int index , vector<string> &output,string &str){

    if(index==str.length()){
        output.push_back(str);
        return;
    }

    for(int j = index ; j<str.size();j++){

        swap(str[index],str[j]);

        printAllPermutation(index+1,output,str);

        // backtrack

        swap(str[index],str[j]);
    }


}

void solve(string s, set<string> &ans, int index){

    if(index>=s.size()){
        ans.insert(s);
        return;
    }

    for(int j= index; j<s.size();j++){

        swap(s[index],s[j]);
        solve(s,ans,index+1);
        swap(s[index],s[j]);
    }
}

int main(){
    string str = "xyz";
    // vector<string> output;
    // int index = 0;

    // printAllPermutation(index,output,str);

    // for(int i=0;i<output.size();i++){
    //     cout<<output[i]<<" ";
    // }
    // cout<<endl;
    
    set<string> ans;
    int index = 0;
    solve(str,ans,index);
    
    vector<string> result;
    for(auto it : ans){
        result.push_back(it);
    }
    


}