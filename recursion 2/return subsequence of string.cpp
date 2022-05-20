#include<iostream>
using namespace std;
#include<string>

int subs(string input, string output[]){
    if(input.empty()){
        output[0] = " ";
        return 1;
    }

    string smallstring = input.substr(1);
    int smallouputsize = subs(smallstring,output);
    for(int i=0;i<smallouputsize;i++){
        output[i+smallouputsize] = input[0]+output[i];
    }

    return 2*smallouputsize;
}

int main(){
    string input;
    cin>>input;

    string* output = new string[1000];
    int count = subs(input,output);  // sbs return how many subseq is there
    for(int i=0;i<count;i++){
        cout<<output[i]<<endl;
    }
}