#include<iostream>
#include<string>
#include<stack>
using namespace std;

int countbracket(string input){

    int len = input.length();

    if(len==0){
        return 0;
    }
    if(len%2!=0){
        return -1;
    }

    stack<char>st;
    
    // removing balaced parentheises
    for(int i=0;i<len;i++){
        if(input[i]=='}' && !st.empty()){
            if(st.top()=='{'){
                st.pop();
            }else{
                st.push(input[i]);
            }
        }
        else{
            st.push(input[i]);
        }
    }
    
    // reduced size
    int reduced_len = st.size();

    int count=0;

    while(!st.empty()){
        char c1 = st.top();
        st.pop();
        char c2 = st.top();
        st.pop();

        if(c1!=c2){
            count+=2;
        }else{
            count+=1;
        }
    }

    return count;
}