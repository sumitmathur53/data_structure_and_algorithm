#include<iostream>
#include<stack>
#include<string>
using namespace std;


bool checkredundance(string s){

    stack<char> st;
    bool ans = false;
    
    for(int i=0;i<s.length();i++){
        if(s[i]=='+' or s[i]=='-' or s[i]=='*' or s[i]=='/'){
             st.push(s[i]);
        }
        else if(s[i]=='('){
            st.push(s[i]);
        }
        else if(s[i]==')'){

            if(st.top()=='('){
                ans = true;
            }

            while(st.top()=='+' or st.top()=='-' or st.top()=='*' or st.top()=='/'){
                st.pop();
            }
            st.pop();
        }
    }

    return ans;
}