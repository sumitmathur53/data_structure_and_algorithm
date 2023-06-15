#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lastRemaining(int n) {
        
        // base case
        if(n==1){
            return n;
        }
         
        return 2* (1+(n/2) - lastRemaining(n/2));
    }
};