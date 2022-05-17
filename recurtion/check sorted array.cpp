#include<iostream>
using namespace std;

bool check(int arr[], int n){
    if(n==0 || n==1){
        return 1;
    }

    if(arr[0]>arr[1]){
        return false;
    }

    return check(arr+1,n-1);

}

int main(){
    int arr[4]={1,2,13,4}; 
    cout<<check(arr,4);
}