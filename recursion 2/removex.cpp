#include<iostream>
using namespace std;

void removex(char s[]){
    if(s[0]=='\0'){
        return;
    }

    if(s[0]!='x'){
        removex(s+1);
    }else{
        int i;
        for(i=1;s[i]!='\0';i++){
            s[i-1]=s[i];   // at this null char not move.
        }
        s[i-1]=s[i];   // run this extra to move null char
        removex(s);
    }
}