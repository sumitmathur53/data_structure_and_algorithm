#include<iostream>
using namespace std;

int length(char input[]){    // in case of charactor no need to pass 
    int count = 0;                         // size as it know by self by '\0'
    for(int i=0;input[i]!='\0';i++){
        count++;
    }
    return count;
}
void reversestring(char input[]){
    int len  = length(input);
    int i=0;
    int j=len-1;

    while(i<j){
        char temp = input[i];
        input[i] = input[j];
        input[j] = temp;
        i++;
        j--;

    }
}
int main(){
    char a[100];
    cin.getline(a,100);
    reversestring(a);
    cout<<a<<endl;
}