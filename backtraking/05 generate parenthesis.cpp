#include<bits/stdc++.h>
using namespace std;

class Solution {
public:


    void solve(string temp, int curropen, int currclose, int remopen, int remclose, 
         vector<string> &result){

            if(remopen==0 && remclose == 0){
                 result.push_back(temp);
                 return;
            }

            // open bracket recursive call
            if(remopen>0){
                temp.push_back('(');
                solve(temp,curropen+1,currclose, remopen-1,remclose, result);

                //backtrack
                temp.pop_back();
            }
            // close bracket recursive call

            if(remclose>0 && curropen > currclose){
                temp.push_back(')');
                solve(temp,curropen,currclose+1, remopen,remclose-1, result);

                temp.pop_back();

            }

    }
    vector<string> generateParenthesis(int n) {
        string temp = "(";
        int curropen = 1;
        int currclose = 0;
        int remopen = n-1;
        int remclose = n;
        vector<string> result;
        solve(temp, curropen, currclose, remopen, remclose, result);
        return result;
    }
};