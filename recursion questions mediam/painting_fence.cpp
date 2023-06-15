#include<bits/stdc++.h>
using namespace std;

// painting fencing problem


int solve(int n, int k){

    // base

    if(n==1){
        return k;
    }

    if(n==2){
        return k*k;
    }

    int same = solve(n-2,k) * (k-1);
    int different = solve(n-1,k) * (k-1);

    return same + different;
}


int main(){

    int n = 5;
    int k = 3;

    int ans = solve(n,k);
    cout<<"ans =>"<<ans<<endl;
}


