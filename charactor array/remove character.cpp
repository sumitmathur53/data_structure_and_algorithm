#include <iostream>
#include <cstring>
using namespace std;

void removeAllOccurrencesOfChar(char input[], char c) {
    int j=0;// storing the required one
    
    for(int i=0;input[i]!='\0';i++){
        if(input[i]!=c){   // if not equal to c then overwrite it in array and j++
            input[j]=input[i];
            j++;
        }
    }
    input[j]='\0';  // at last we have to put the null at end
}

int main() {
    int size = 1e6;
    char str[size];
    cin.getline(str, size);
    char c;
    cin >> c;
    removeAllOccurrencesOfChar(str, c);
    cout << str;
}