#include<iostream>
using namespace std;
#include<string>
#include<stack>

void reverse(string s){
    stack<string> st;

    for(int i=0;i<s.size();i++){
        string word = "";

        while(s[i]!=' ' && i<s.length()){
            word+=s[i];
            i++;
        }
        st.push(word);
    }

    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }cout<<endl;
    
}

int main(){
     reverse("heb baby u ok");
}