#include <iostream>
#include<string.h>
using namespace std;

void replacePi(char input[]) {
	
    if(input[0]=='\0' || input[1]=='\0'){  // if string is 0 or 1 size
        return;
    }
    
    if(input[0]=='p' && input[1]=='i'){   // we doing this only if we get pi first
        input[0]='3';
        input[1]='.';
        
        int len = strlen(input);    // incrasing the size of the input
        for(int i=len+2; i>1; i--){
            input[i] = input[i-2];
        }
        
        input[2]='1';
        input[3]='4';
    }
    
    replacePi(input+1);
    

}

int main() {
    char input[10000];
    cin.getline(input, 10000);
    replacePi(input);
    cout << input << endl;
}
