#include<iostream>
using namespace std;
#include<string>

string getString(int d){
    if(d==2){
        return "abc";
    }
    if(d==3){
        return "def";
    }
    if(d==4){
        return "ghi";
    }
    if(d==5){
        return "jkl";
    }
    if(d==6){
        return "mno";
    }
    if(d==7){
        return "pqrs";
    }
    if(d==8){
        return "tuv";
    }
    if(d==9){
        return "wxyz";
    }
    return " ";
}

int keypad(int input, string output[]){
    if(input==0){
        output[0]="";
        return 1;
    }

    int lastdigit = input%10;
    int smallnumber = input/10;
    int smalloutputsize = keypad(smallnumber,output);

    string options = getString(lastdigit);

    for(int i=0;i<options.size()-1;i++){
        for(int j=0;j<smallnumber;j++){
            output[j + (i+1)*smalloutputsize] = output[j];
        }
    }

    int k=0;
    for(int i=0;i<options.size();i++){
        for(int j=0;j<smalloutputsize;j++){
            output[k] = output[k]+options[i];
            k++;
        }
    }

    return smalloutputsize*options.size();
}

int main(){
    int n;
    cin>>n;
    string output[1000];
    int count = keypad(n,output);
    for(int i=0;i<count;i++){
        cout<<output[i]<<" ";
    }
}