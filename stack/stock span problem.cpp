#include<iostream>
#include<stack>
using namespace std;

int* stackspan(int price[], int size){
    int * output = new int[size];
    stack<int> st;

    st.push(0);   // put index of 0 in stack
    output[0] = 1; // first ans always 1

    for(int i=1;i<size;i++){
        
        // Pop elements from stack while stack is not
        // empty and top of stack is smaller than
        // price[i]
        while(!st.empty() && price[st.top()]<price[i]){
            st.pop();
        }
        // If stack becomes empty, then price[i] is
        // greater than all elements on left of it,
        // i.e., price[0], price[1], ..price[i-1].  Else
        // price[i] is greater than elements after
        // top of stack
        if(st.empty()){
            output[i] = (i+1);
        }else{
            output[i] = (i-st.top());
        }
        st.push(i);
    }
    return output;
}