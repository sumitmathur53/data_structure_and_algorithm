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
void printkeypad(int n, string output){
    if(n==0){
        cout<<output<<endl;
        return;
    }

    int lastdigit = n%10;
    int smallnumber = n/10;

    string options = getString(lastdigit);
    
    for(int i=0;i<options.size();i++){
        printkeypad(smallnumber,options[i]+output);
    }
}
int main(){
    int n;
    cin>>n;
    printkeypad(n,"");
}