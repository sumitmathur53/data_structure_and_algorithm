#include<iostream>
using namespace std;

int main(){
    char c;
    c = cin.get();

    int ch = 0;
    int in = 0;
    int sp = 0;

    while(c!='$'){
        if(c>='0' && c<='9'){
            in++;
        }else if(c==' '|| c=='\t' || c=='\n'){
            sp++;
        }else{
            ch++;
        }

        c= cin.get();
    }

    cout<<ch<<" "<<in<<" "<<sp;
}