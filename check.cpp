#include<iostream>
using namespace std;
#include<bits/stdc++.h>

bool check(int arr[], int n){
    if(n==0 || n==1){
        return true;
    }

    if(arr[0]>arr[1]){
        return 0;
    }
    return check(arr+1,n-1);

}

int main(){
    int arr[]={1,5,13,96};
    cout<<check(arr,4);

}