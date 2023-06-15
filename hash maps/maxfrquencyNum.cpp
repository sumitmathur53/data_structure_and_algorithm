#include<iostream>
#include<unordered_map>
using namespace std;

int hihestfreq(int arr[], int n){

    unordered_map<int, int> freq;

    for(int i=0;i<n;i++){
        freq[arr[i]]++;
    }

    int ans = 0;
    int value = 0;

    for(int i=0;i<n;i++){
        if(value<freq[arr[i]]){
            ans = arr[i];
            value = freq[arr[i]];
        }
    }

    return ans;
}