#include<iostream>
#include<string>
using namespace std;


void print_sub(string input, string output){
    if(input.length()==0){
        cout<<output<<endl;
        return;
    }

    print_sub(input.substr(1),output);
    print_sub(input.substr(1),output+input[0]);
    
}

int main(){
    print_sub("abc","");

}