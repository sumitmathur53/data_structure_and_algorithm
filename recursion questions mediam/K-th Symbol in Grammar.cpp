#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kthGrammar(int n, int k) {
        // base case

        if(n==1){
            return 0;
        }

        int parent = kthGrammar(n-1, k/2 + k%2); // position of parent

        if(parent == 0){
            if(k&1){  // if k is odd
               return 0;
            }
            else{
                return 1;
            }
        }
        else{
            //parent ==1
            if(k&1){
                return 1;
            }
            else{
                return 0;
            }
        }
    }
};