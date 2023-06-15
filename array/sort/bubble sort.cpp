#include<iostream>
using namespace std;
#include<bits/stdc++.h>

void bubble(int arr[], int n){

     for(int i=0;i<n-1;i++){

         for(int j=i+1;j<n;j++){
             if(arr[j]<arr[i]){
                 int temp = arr[j];
                 arr[j] = arr[i];
                 arr[i] = temp;
             }
         }
    }
}

void rotate(int n, int arr[], int d){
    for(int i=1;i<d;i++){
        int temp = arr[0];
        for(int k = 0;k<n-1;k++){
            arr[k] = arr[k+1];
        }
        arr[n-1] = temp;
    }
}

void reversing(int n,int arr[]){

    int s = 0;
    int e = n-1;

    while(s<e){
        int temp = arr[s];
        arr[s] = arr[e];
        arr[e] = temp;
        s++;
        e--;
    }
}

void secondLargest(int n, int arr[]){
    int largest = INT_MIN;
    int secL = INT_MIN;

    for(int i=0;i<n;i++){
        if(arr[i]>largest){
            int temp = largest;
            largest = arr[i];
            secL = temp;
        }

        if(arr[i]<largest  && arr[i]>secL){
            secL = arr[i];
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
    bubble(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

}