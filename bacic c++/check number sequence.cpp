#include<iostream>
using namespace std;

int main(){
    int n; // how many value user give?
    cin>>n;

    int p;  // prevous number 
    cin>>p;

    bool isdec = true;
    bool is_valid = true;
    int i=1;
    while(i<=n-1){
        int c;
        cin>>c;

        if(is_valid && isdec && p>c){
            p=c;
            isdec=true;
        }else if(is_valid && p<c){
            p=c;
            isdec=false;
        }else{
            is_valid=false;
        }
        
        i++;

    }

    if(is_valid){
        cout<<"true"<<endl;
    }else{
        cout<<"false"<<endl;
    }
}