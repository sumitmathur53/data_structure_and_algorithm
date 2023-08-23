#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    void solve(vector<int> &nums, int index, int &xorAns, int &sum){

        if(index == nums.size()){
            sum += xorAns;
            return;
        }

        // inculde
        xorAns = xorAns ^ nums[index];
        solve(nums,index+1, xorAns, sum);

        //backtrack
        xorAns = xorAns ^ nums[index];

        // exclude
        solve(nums,index+1, xorAns, sum);
    }
    int subsetXORSum(vector<int>& nums) {
        int sum = 0;
        int xorAns = 0;
        int index = 0;

        solve(nums,index,xorAns,sum);
        return sum;
    }
};