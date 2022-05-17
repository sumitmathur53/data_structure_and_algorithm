#include<iostream>
using namespace std;

// store the maximum in one variable
bool check(int x, int y, int z){
    int a = max(x,max(y,z));
    int b,c;

    if(a==x){
        b=y;
        c=z;
    }
    else if(a==y){
        b=x;
        c=z;
    }
    else{
        b=x;
        c=y;
    }
    if(a*a==b*b+c*c){
        return true;
    }else{
        return false;
    }
}

int main(){
    int a,b,c;
    cin>>a>>b>>c;

    if(check(a,b,c)){
        cout<<"pythagoras triplet"<<endl;
    }else{
        cout<<"no";
    }
}