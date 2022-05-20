#include <iostream>
using namespace std;
#include<string.h>
#include<bits/stdc++.h>
int stringToNumber(char input[]) {
    
    if(input[1]=='\0'){
        int p = input[0]-'0';
        return p;
    }
    
    int len = strlen(input);
    int ans = stringToNumber(input+1);
    
    int b = input[0]-'0';
    
    return b*(pow(10,(len-1)))+ans;
    
}

int main() {
    char input[50];
    cin >> input;
    cout << stringToNumber(input) << endl;
}
