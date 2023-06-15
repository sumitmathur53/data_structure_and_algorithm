#include<iostream>
using namespace std;

#include<unordered_map>
#include<string>
#include<vector>


string extractUniqueCharactor(string str){

    unordered_map<char, int> charCount;

    string ans;

    for(int i=0;i<str.size();i++){
        charCount[str[i]]++;

        if(charCount[str[i]]==1){
            ans.push_back(str[i]);
        }
    }
    return ans;
}