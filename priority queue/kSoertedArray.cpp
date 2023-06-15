#include<iostream>
using namespace std;
#include<queue>


void kSorted(int arr[], int n, int k){

    priority_queue<int> pq;  // insert first k element in this 

    for(int i=0;i<k;i++){
        pq.push(arr[i]);
    }

    int j=0;   // sorted array index for which finding value

    for(int i=k;i<n;i++){
        arr[j] = pq.top();  // put top of pq in array which is max one
        pq.pop();          
        pq.push(arr[i]);
        j++;
    }

    // after this loop our array is sorted till n-k;
    // last k elements still present in pq

    while(!pq.empty()){
        arr[j] = pq.top();
        pq.pop();
        j++;
    }

}

int main(){
      int arr[] = {10,12,6,7,9};
      int k=3;
      kSorted(arr,5,k);
      for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
      }
}
