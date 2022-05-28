#include<iostream>
using namespace std;

void insertionsort(int arr[], int n){
     // asume 0 element is at correct location
     // next check is at 1 position
   for(int i=1;i<n;i++){     
       int current = arr[i];  // store the current
       int j= i-1;
       for( ; j>=0; j--){
           if(current < arr[j]){
               arr[j+1] = arr[j];
           }else{
               break;
           }
       }
       arr[j+1] = current;
   }
}


int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    insertionsort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
} 