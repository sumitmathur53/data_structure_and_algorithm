#include<iostream>
using namespace std;
#include<stack>

void reverseStack(stack<int> &input, stack<int> &extra) {    
    if(input.empty()){
        return;
    }   
    int x = input.top();   // store the first element
    input.pop();
    
    reverseStack(input,extra);  // except the first one all are reversed now
    
    // to put the top which we saved in x 
    // have to put it in bottom
    // so first we have to remove all the element from stack input
    // put them into extra stack 
    

    while(!input.empty()){    
        int temp = input.top();
        input.pop();
        extra.push(temp);
    }

    //and put the x (first) at bottom of input
    input.push(x);
    
    // shift element from extra to input
    while(!extra.empty()){
        int temp = extra.top();
        extra.pop();
        input.push(temp);
    }
    
}