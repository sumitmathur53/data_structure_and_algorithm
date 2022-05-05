#include <iostream>
#include <cstring>
using namespace std;

bool isPermutation(char input1[], char input2[]) {
    
   int count1[256]={0};  // frequency array for each string
   int count2[256]={0};
    
    int len1 = strlen(input1);  // length
    int len2 = strlen(input2);
    
    for(int i=0;i<len1;i++){   // count the frequency
        count1[input1[i]]++;
    }
    for(int i=0;i<len2;i++){
        count2[input2[i]]++;
    }
    
    if(len1!=len2){          // if length is not equal 
        return false;
    }
    
    for(int i=0;i<256;i++){
        if(count1[i]!=count2[i]){   // if frequency not equal
            return false;
        }
    }
    
    return true;
}

int main() {
    int size = 1e6;
    char str1[size];
    char str2[size];
    cin >> str1 >> str2;
    cout << (isPermutation(str1, str2) ? "true" : "false");
}