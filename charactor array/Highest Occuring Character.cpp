#include <iostream>
#include <cstring>
using namespace std;


char highestOccurringChar(char input[]) {
    
    // creating frequency array of 256 (ASCII_SIZE)
    
    int freq[256] = {0};   // initialise with zero
    
    int length = strlen(input);
    
    int max = 0;
    char result = input[0] ;
    
    
    for(int i=0;i<length;i++){
        freq[input[i]]++;
        
    }
    for(int i=0;i<256;i++){
        if(freq[input[i]]>max){
            max = freq[input[i]];
            result = input[i];
        }
    }
    return result;
}

int main() {
    int size = 1e6;
    char str[size];
    cin >> str;
    cout << highestOccurringChar(str);
}