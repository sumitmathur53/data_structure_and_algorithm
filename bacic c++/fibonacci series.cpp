#include<iostream>
using namespace std;


void fibo(int n){
    int a = 0;
    int b = 1;
    int next;
    for(int i=2;i<=n;i++){
        cout<<a<<" ";
        next = a+b;
        a=b;
        b=next;
    }
}

int main(){
    int n;
    cin>>n;
    fibo(n);
}