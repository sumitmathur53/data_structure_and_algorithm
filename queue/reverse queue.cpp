#include<iostream>
#include<queue>
using namespace std;

void reverse(queue<int> q){
    if(q.empty()){
        return;
    }
    
    // Store the front element in a variable.
    int temp = q.front();
    q.pop();

    // Recursively call for the rest of the queue
    reverse(q);

    q.push(temp);
}