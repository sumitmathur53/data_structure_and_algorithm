
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int p1_score(vector<int>& nums, int i, int j){

        if(i>j){
            return 0;
        }
        // when there is only one element in array
        if(i==j){
            return nums[i];
        }

        int option_1 = nums[i] + min(p1_score(nums,i+2,j) , p1_score(nums,i+1,j-1));
        int option_2 = nums[j] + min(p1_score(nums,i,j-2), p1_score(nums,i+1,j-1));

        return max(option_1,option_2);
    }


    bool PredictTheWinner(vector<int>& nums) {
        
        int p1_sc = p1_score(nums, 0, nums.size()-1);

        int totalscore = 0;

        for(int i=0;i<nums.size();i++){
            totalscore += nums[i];
        }

        int p2_score = totalscore - p1_sc;

        if(p1_sc >= p2_score){
            return true;
        }else{
            return false;
        }
    }
};