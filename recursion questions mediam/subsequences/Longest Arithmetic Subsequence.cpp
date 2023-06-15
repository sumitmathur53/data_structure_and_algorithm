#include<bits/stdc++.h>
using namespace std;

class Solution {
public:


    int backCheck(int i, vector<int>& nums , int difference){
        if(i<0){
            return 0;
        }

        int ans = 0;

        for(int k = i-1; k>=0; k--){

            if(nums[i] - nums[k] == difference){

                // number of ap is found

                ans = max( ans , 1 + backCheck(k, nums, difference));
            }
        }

        return ans;
    
    }
    int longestArithSeqLength(vector<int>& nums) {

        int ans = 0;

        for(int i=0;i<nums.size();i++){
            
            for(int j=i+1;j<nums.size();j++){

                int difference = nums[j]-nums[i];

                // here we are adding 2 as we are check backward,
                // we already have 2 element i and j as of ap, we want to 
                // add more element in our ap array if valid by
                // checking backward function

                ans = max(ans , 2 + backCheck(i , nums , difference));

            }
        }

        return ans;
        
    }
};