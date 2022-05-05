#include<iostream>
using namespace std;

int length(char input[]){    // in case of charactor no need to pass 
    int count = 0;                         // size as it know by self by '\0'
    for(int i=0;input[i]!='\0';i++){
        count++;
    }
    return count;
}

int main(){
    char a[100];
    cin>>a;
    cout<<a<<endl;

    cout<<"length of string -> "<<length(a);


}