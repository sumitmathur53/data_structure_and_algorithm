#include<iostream>
using namespace std;
// decimal to binary
int main(){
    int n;
    cin>>n;

    long int binary = 0;
    int remainder=0;
    long int i=1;

    while(n!=0){
        remainder = n%2;
        binary += remainder*i;
        i=i*10;
        n=n/2;
    }
    cout<<binary;
}