#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;

    int n1 = (n+1)/2;
    int n2 = n1-1;

    for(int i=1;i<=n1;i++){
        for(int j=1;j<=n1-i;j++){
            cout<<" ";
        }
        for(int k=1;k<=2*i-1;k++){
            cout<<"*";
        }cout<<endl;
    }

    for(int i=n2;i>=1;i--){
        for(int j=1;j<=(n2-i+1);j++){
            cout<<" ";
        }
        for(int k=1;k<=(2*i-1);k++){
            cout<<"*";
        }cout<<endl;
    }
}