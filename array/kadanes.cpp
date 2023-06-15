// maximum subarray sum

#include<iostream>
using namespace std;
#include<bits/stdc++.h>



int main(){
    int n;
    cin>>n;
    int arr[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int currSum = 0;
    int maxSum = INT_MIN;

    for(int i=0;i<n;i++){
        currSum += arr[i];

        if(currSum<0){
            currSum = 0;
        }

        maxSum = max(maxSum,currSum);
    }

    cout<<maxSum;
}