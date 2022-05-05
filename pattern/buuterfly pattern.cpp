#include<iostream>
using namespace std;

int main(){

    int n;
    cin>>n;
    // this pattern can be divided into 2 part 

    // printing upper part
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout<<"*";
        }
        int space = 2*n-2*i;      // printing the space
        for(int j=1;j<=space;j++){
            cout<<" ";
        }
        for(int j=1;j<=i;j++){
            cout<<"*";
        }cout<<endl;
    }

    // now printing lower part

    for(int i=n;i>=1;i--){
        for(int j=1;j<=i;j++){
            cout<<"*";
        }
        int space = 2*n-2*i;      // printing the space
        for(int j=1;j<=space;j++){
            cout<<" ";
        }
        for(int j=1;j<=i;j++){
            cout<<"*";
        }cout<<endl;
    }
}