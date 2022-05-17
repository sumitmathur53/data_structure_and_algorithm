#include<iostream>
using namespace std;

int binarytodesimal(long int n){
    int ans = 0;
    int x=1;

    while(n>0){
        int lastdigit = n%10;
        ans += x*lastdigit;
        x*=2;
        n=n/10;
    }
    return ans;
}

int main(){
    long int n;
    cin>>n;

    cout<<binarytodesimal(n);
}