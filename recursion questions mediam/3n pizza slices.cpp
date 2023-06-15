#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int solve(vector<int>& slices, int s, int e, int n){

        // base case

        if(n==0 || s>e){
            return 0;
        }

        int include = slices[s] + solve(slices, s+2, e, n-1); // include 1
        int exclude = 0 + solve(slices , s+1, e, n);        // exclude 1

        return max(include,exclude);


    }
    int maxSizeSlices(vector<int>& slices) {


        // 3n slices
        int totalSlice = slices.size();

        int option1 = solve(slices , 0, slices.size()-2 , totalSlice/3);
        int option2 = solve(slices,  1, slices.size()-1, totalSlice/3);

        return max(option1,option2);
        
    }
};