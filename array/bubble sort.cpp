#include<iostream>
using namespace std;

void bubblesort(int arr[], int n){

    int counter = 1;
    while(counter<n){
        for(int i=0;i<n-counter;i++){   //    here we are going to n-1 timesto sort
            if(arr[i]>arr[i+1]){
                int temp = arr[i+1];
                arr[i+1] = arr[i];
                arr[i] = temp;
            }
        }
        counter++;
    }

}
int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    bubblesort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

}