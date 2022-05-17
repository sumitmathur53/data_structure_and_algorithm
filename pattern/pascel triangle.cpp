#include<iostream>
using namespace std;

// pascal triangle;

int facto(int n){
    int fact = 1;
    for(int i=2;i<=n;i++){
        fact = fact*i;
    }
    return fact;
}

int main(){
    int n;
    cin>>n;

    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cout<<facto(i)/(facto(i-j)*facto(j))<<" ";
        }cout<<endl;
    }
}

