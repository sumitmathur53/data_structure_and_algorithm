#include<iostream>
using namespace std;

/// 0 1 1 2 3 5 8 13 21 34 55 89 144 233 377 610 987 1597

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