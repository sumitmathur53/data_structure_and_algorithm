#include<iostream>
using namespace std;
#include<unordered_map>
#include<vector>


vector<int> removeDuplicate(int arr[], int n){

    vector<int> ans;

    unordered_map<int,bool> seen;  // key is integer and value is bool

    for(int i=0;i<n;i++){
        if(seen.count(arr[i])>0){
            continue;
        }
        seen[arr[i]] = true;
        ans.push_back(arr[i]);
    }

    return ans;
 
}

int main(){
    int arr[] = {1,2,3,3,2,1,4,5,2};
    vector<int> p = removeDuplicate(arr,9);

    for(int i=0;i<p.size();i++){

        cout<<p[i]<<" ";

    }
}