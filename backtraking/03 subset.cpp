#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(vector<int>& nums, vector<vector<int>>& result, vector<int> &ans, int index){

        // base case;
        if(index == nums.size()){
            result.push_back(ans);
            return;
        }

        // include

        ans.push_back(nums[index]);
        solve(nums,result,ans,index+1);

        // baktrack
        ans.pop_back();

        // exclude
        solve(nums,result,ans,index+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
       vector<vector<int>> result;
       vector<int> ans;
        int index = 0;

       solve(nums,result,ans,index); 
       return result;
    }
};