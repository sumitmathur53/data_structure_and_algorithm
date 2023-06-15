#include<iostream>
#include<vector>
#include<queue>
using namespace std;



vector<int> kSmallest(int arr[], int n, int k) {
    // Write your code here
    
    priority_queue <int> pq;
    
    for(int i=0;i<k;i++){  // inserting first k element
        pq.push(arr[i]);
    }
    
    for(int i=k;i<n;i++){      // checking the incoming element if its small then add to it
        if(arr[i] < pq.top()){
            pq.pop();
            pq.push(arr[i]);
        }
    }
    
    // convert heap to vector
    
    vector<int>ans;
    
    while(!pq.empty()){
        ans.push_back(pq.top());
        pq.pop();
    }
    
    return ans;
    
}