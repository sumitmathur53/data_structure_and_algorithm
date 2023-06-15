#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int solve(string s, string t, int i, int j){

        if(i == s.length()){
            return 0;
        }
        if(j == t.length()){
            return 0;
        }

        int ans = 0;

        if(s[i]==t[j]){
            ans = 1 + solve(s,t,i+1,j+1);
        }
        else{
            ans = max(solve(s,t,i+1,j), solve(s,t,i,j+1));
        }

        return ans;
    }
    int longestCommonSubsequence(string s, string t) {

        int i = 0;
        int j = 0;

        return solve(s,t,i,j);
        
    }
};