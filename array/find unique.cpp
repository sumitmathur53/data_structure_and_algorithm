#include<iostream>
using namespace std;

int unique(int arr[], int n){

    for(int i=0;i<n;i++){
        int j;
        for(j=0;j<n;j++){
            if(i!=j){
                if(arr[i]==arr[j]){
                    break;
                }
            }

            
        }
        
        if(j==n){
            return arr[i];
        }
    }
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<unique(arr,n);
}