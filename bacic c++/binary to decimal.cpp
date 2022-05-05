#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;

    int result = 0;
    int base = 1;

    while(n>0){
        int last = n%10;
        result = result + last*base;
        base*=2;
        n=n/10;
    }
    cout<<result;
}