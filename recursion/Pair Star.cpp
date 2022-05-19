#include <iostream>
#include<string.h>
using namespace std;
void pairStar(char input[]) {
    
    if(input[0]=='\0' || input[1]=='\0'){
        return;
    }
    
    pairStar(input+1);
    
    if(input[0]==input[1]){
        
        int l = strlen(input);
        
        input[l+1]='\0';  // extending string
        
        int i;
        
        for(i=l-1;i>=0+1;i--){  // shifting one step
            input[i+1]=input[i];
        }
        
        input[0+1]='*';
    }

}

int main() {
   char input[100];
   cin.getline(input, 100);
   pairStar(input);
   cout << input << endl;
}
