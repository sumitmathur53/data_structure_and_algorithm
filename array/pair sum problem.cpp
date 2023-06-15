#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// maximum pair sum problem

bool pairsum(int arr[], int n, int key){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]+arr[j] == key){

                cout<<i<<" "<<j<<endl;
                return true;
            }
        }
    }

    return false;
}

// time complexety of the above pair is o(n^2)

// for this we need to sort the array

bool binary_pair_sum(int arr[], int n, int key){

    int low = 0;
    int end = n-1;

    while(low<end){
        if(arr[low]+arr[end]==key){
            cout<<low<<" "<<end;
            return true;
        }
        else if(arr[low]+arr[end] > key){
            end--;
        }
        else{
            low++;
        }
    }
    return false;
}

// for this the time complexity is o(n);