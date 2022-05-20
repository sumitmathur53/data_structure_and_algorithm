#include<iostream>
using namespace std;

#include<string.h>
bool checkPalindrome(char input[]) {
    static int s = 0;
    int e = strlen(input);
    
    if(s>=e){
        return true;
    }
    if(input[s]!=input[e-s-1]){
        return false;
    }else{
        s++;
        checkPalindrome(input);
    }
}


int main() {
    char input[50];
    cin >> input;
    
    if(checkPalindrome(input)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}
