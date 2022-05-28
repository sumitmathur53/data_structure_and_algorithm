#include<iostream>
using namespace std;



void selectionsort(int arr[], int n){

    // find the minimum element

   for(int i=0;i<n-1;i++){
        int min = arr[i];
        int minindex = i;         // to know min index to place first elemnt 
        for(int j=i+1;j<n;j++){
            if(arr[j]<min){
                min = arr[j];
                minindex = j;
            }
        }
    
        int temp = arr[i];
        arr[i] = arr[minindex];
        arr[minindex] = temp;
   }

}
int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    selectionsort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

}